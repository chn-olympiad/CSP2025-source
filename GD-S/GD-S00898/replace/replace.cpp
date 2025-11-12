#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a.size()<s1[i].size()) continue;
			for(int j=0;j<=a.size()-s1[i].size();j++){
				bool flag=1;
				string tmp=a;
				for(int k=0;k<s1[i].size();k++){
					tmp[j+k]=s2[i][k];
					if(a[j+k]!=s1[i][k]){
						flag=0;
						break;
					}
				}
				if(flag&&tmp==b) ans++;
			}
		}
		printf("%d\n",ans);
	} 
	return 0; 
}
