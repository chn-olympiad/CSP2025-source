#include<bits/stdc++.h>
using namespace std;
int n,m,wz,fz,z;
bool zj;
int s[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	fz=s[1];
	sort(s+1,s+1+n*m);
	for(int i=1;i<=n*m;i++)if(fz==s[i])wz=n*m-i+1;
	zj=1;
	for(int j=1;j<=m;j++){
		if(zj){
			for(int i=1;i<=n;i++){
				z++;
				if(z==wz){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				z++;
				if(z==wz){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}
		zj=!zj;
	}
	return 0;
}
