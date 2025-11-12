#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	int sum=m*n;
	sort(a+1,a+1+m*n);
	int l=1,r=n*m;
	while(l<=r){
		int mid=(l+r)/2;
		if(ans<=a[mid]){
			r=mid;
		}if(ans>=a[mid]){
			l=mid;
		}if(l==r){
			int s=sum-l+1;
			if(s%n==0){
				if((s/n)%2==0){
					cout<<s/n<<" "<<"1";
				}else{
					cout<<s/n<<" "<<n;
				}
			}else{
				if((s/n)%2==0){
					cout<<s/n+1<<" "<<s%n;
				}else{
					cout<<s/n+1<<" "<<n+1-s%n;
				}
			}return 0;
		}
	}
	return 0;
}
