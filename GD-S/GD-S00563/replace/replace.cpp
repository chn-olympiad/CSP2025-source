#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[200005],s2[200005],t1,t2;
map<string,bool>appear1,appear2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i],appear1[s1[i]]=1,appear2[s2[i]]=1;
	while(q--){
		cin>>t1>>t2;
		int l,r;
		l=r=0;
		for(int i=0;i<t1.size();i++)
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		for(int i=t1.size()-1;i>=0;i--)
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}
		for(int i=0;i<=l;i++){
			if(l>r) continue;
			string tmp1,tmp2;
			for(int j=i;j<r;j++) tmp1+=t1[j],tmp2+=t2[j];
			for(int j=r;j<=t1.size();j++){
				tmp1+=t1[j],tmp2+=t2[j];
//				cout<<tmp1<<' '<<tmp2<<' '<<appear1[tmp1]<<' '<<appear2[tmp2]<<'\n';
				if(appear1[tmp1]&&appear2[tmp2]) ans++;
			}
		}
		cout<<ans<<'\n';
		ans=0;
		appear1.clear();
		appear2.clear();
	}
}
