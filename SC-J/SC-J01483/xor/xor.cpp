#include<bits/stdc++.h>
using namespace std;
int n,k,x,ans;
vector<int> s(5e5+10,0),f(5e5+10,0);
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		s[i]=(s[i-1]^x);
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k&&(!f[i])) f[i]=j;
		}
	}int i=1;
	while(i<=n){
		if(f[i]){
			bool b=true;
			for(int j=i+1;j<f[i];j++){
				if(f[j]&&f[j]<f[i]){
					i=j;
					b=false;
					break;
				}
			}if(b){
				ans++;
				i=f[i]+1;
			}
		}else i++;
	}printf("%d",ans);
	return 0;
}