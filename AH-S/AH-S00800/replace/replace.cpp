#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
map<string,string> m;
map<int,string> mp;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		m[s1]=s2;
		mp[i]=s1;
	}
	while(q--){
		ans=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			string y=mp[i];
			int op=0,l1=s1.size(),ly=y.size();
			if(ly>l1) continue;
			for(int j=0;j<=l1-ly;j++){
				for(int k=0;k<j;k++) {
					if(s1[k]!=s2[k]) break;
				}
				if(s1[j]==y[op]){
					while(y[op+1]==s1[j+op+1]&&op+1<ly) op++;
					if(op==ly-1){
						string s4,yy=m[y];
						if(j>0) for(int k=0;k<j;k++) s4+=s1[k];
						for(int k=j;k<=j+op;k++) s4+=yy[k-j];
						for(int k=j+op+1;k<l1;k++) s4+=s1[k];
						if(s4==s2) ans++;
					}
					op=0;
				}
			}
		}
		printf("%d\n",ans);
	}
}
