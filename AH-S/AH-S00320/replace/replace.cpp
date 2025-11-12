#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200010];
map<string,string> m;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
		string s2;
		cin>>s[i]>>s2;
		m[s[i]]=s2;
	}
	while(q--){
		string t1,t2,ans1,ans2;
		int cnt=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			int p1=t1.find(s[i]),p2=t2.find(m[s[i]]);
			if(p1!=string::npos&&p2!=string::npos){
				int f=0;
				for(int j=0;j<p1;j++){
					if(t1[j]!=t2[j]){
						f=1;
						break;
					}
				}
				for(int j=p1+s[i].size();j<t1.size();j++){
					if(t1[j]!=t2[j]){
						f=1;
						break;
					}
				}
				if(f==0)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
    return 0;
}
