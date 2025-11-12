#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string t1,t2,s[3];
long long ans;
unordered_map<pair<string,string>,int>m,my;
void init(){
	ans=0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[1]>>s[2];
		my[s[1]]=s[2];
		m[]++;
	}
	for(int i=1;i<=q;i++){
		init();
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0;continue;
		}
		for(int i=0;i<t1.size();i++){
			if(i>0&&t1[i-1]!=t2[i-1])break;
			for(int j=i;j<t1.size();j++){
				for(int k=j+1;k<t1.size();k++)if(t1[k]!=t2[k])break;
				string stmp1=t1.substr(i,j-i+1),stmp2=t2.substr(i,j-i+1);
				if(m[stmp1].count())ans+=1ll*m[stmp1]; 
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
