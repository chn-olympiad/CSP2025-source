#include <bits/stdc++.h>
using namespace std;
string gghh;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	string a[n+10][10]{};
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	while(q--){
		string u,v;
		cin>>u>>v;
		int len=u.length();
		int ans=0;
		for(int i=1;i<=n;i++){
			int len1=a[i][1].length();
			string gg=gghh;
			for(int j=0;j+len1<=len;j++){
				if(u[j]!=a[i][1][0]){
					gg+=u[j];
					continue;
				}
				int ggg=0;
				for(int r=0;r<len1;r++){
					if(u[j+r]!=a[i][1][r]){
						ggg=1;
						break;
					}
				}
				if(ggg){
					gg+=u[j];
					continue;
				}
				string h=gg;
				h+=a[i][2];
				for(int r=j+len1;r<len;r++){
					h+=u[r];
				}
				if(h==v){
					ans++;
				}
				gg+=u[j];
			}
		}
		printf("%d",ans);
	}
	return 0;
}
