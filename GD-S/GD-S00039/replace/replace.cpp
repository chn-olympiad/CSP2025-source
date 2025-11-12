#include<bits/stdc++.h>
using namespace std;
int n,T;
string x[200005],y[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	while(T--){
		int ans=0;
		string a,b;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(int)a.size();j++){
				if(x[i][0]==a[j]){
					if(int(a.size())-j<int(x[i].size())) continue;
					bool f=0;
					for(int k=0;k<(int)x[i].size();k++){
						if(x[i][k]!=a[j+k]){
							f=1;
							break;
						}
					}
					if(f==1) continue;
					string t=a;
					for(int k=0;k<(int)y[i].size();k++){
						t[j+k]=y[i][k];
					}
					if(t==b) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
