#include<bits/stdc++.h>
using namespace std;
int n,m,p,cnt=1,flag=0;
int c[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>c[i];
		p=c[0];
		if(c[i]>p){
			cnt++;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				flag++;
				if(flag==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>0;j--){
				flag++;
				if(flag==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}