#include<bits/stdc++.h>
using namespace std;
string s[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q--){
		string tx,ty;
		cin>>tx>>ty;
		if(tx.size()!=ty.size()){
			puts("0");
			continue;
		}
		int l=tx.size(),le=0,re=l-1;
		while(le<l&&tx[le]==ty[le])le++;
		while(re>=0&&tx[re]==ty[re])re--;
		int ans=0;
		for(int i=1;i<=n;i++){
			int r=s[i][0].size();
			for(int j=0;j+r-1<l;j++){
				int f=0,is=1;
				for(;f<r;f++){
					if(tx[j+f]!=s[i][0][f]){
						is=0;
						break;
					}
				}
				if(is&&j<=le&&j+f-1>=re){
					int f=0,is=1;
					for(;f<r;f++){
						if(ty[j+f]!=s[i][1][f]){
							is=0;
							break;
						}
					}
					if(is)ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
