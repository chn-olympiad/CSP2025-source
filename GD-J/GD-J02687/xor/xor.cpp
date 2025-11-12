#include<bits/stdc++.h>
using namespace std;
const int MX=5e5+5;
int a[MX],c[MX],n,k;
bool ch[MX];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(a,0,sizeof(a));memset(c,0,sizeof(c));
	memset(ch,true,sizeof(ch));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=(a[i]^c[i-1]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((c[j]^c[i])==k&&(ch[j]&&ch[i])){
				ans++;//cout<<i<<' '<<j<<' ';
				for(int x=i;x<=j;x++){
					ch[x]=false;
				}
			} 
		}
	}cout<<ans;
	return 0;
}
