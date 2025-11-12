#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	int a[1086];
	cin>>a[1];
	int q=a[1];
	for(int i=2;i<=sum;i++){
		cin>>a[i];
		}
		for(int i=1;i<=sum;i++){
			for(int j=2;j<=sum;j++){
				if(a[j]>a[j-1]){
					swap(a[j],a[j-1]);
					}
				}
			}
			int x;
		int l=1,r=sum,mid;
			while(l<=r){
			mid=(l+r)/2;
		 if(a[mid]>q)l=mid+1;
		 if(a[mid]<q)r=mid-1;
		 if(a[mid]==q){
			 x=mid;
			 break;
			 } 
		}
		int y=x/n;
		if(y%2==0&&x%n!=0){
			cout<<y+1<<" "<<x%n;
			}else if(y%2==0&&x%n==0){
				cout<<y<<" "<<x%n+1;
			}else if(y%2!=0&&x%n!=0){
				cout<<y+1<<" "<<n-x%n+1;
			}else if(y%2!=0&&x%n==0){
			    cout<<y<<" "<<n;
			}
	}
