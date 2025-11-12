#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int s,k,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==s){
			k=n*m-i+1;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				num++;
				if(num==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				num++;
				if(num==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
