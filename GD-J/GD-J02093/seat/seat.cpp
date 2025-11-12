#include<bits/stdc++.h>
using namespace std;
int a[10001],ls,pos,sum,n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	ls=a[1];
	sort(a+1,a+n*m+1,greater<>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==ls){
			pos=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				sum++;
				if(sum==pos){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				sum++;
				if(sum==pos){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
} 
