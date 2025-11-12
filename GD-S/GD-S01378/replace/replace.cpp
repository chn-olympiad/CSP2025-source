#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[100010],s2[100010],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		ans=0;
		for(int p=1;p<=n;p++){
			bool flag=1;
			for(int j=0;j<t1.size();j++){
				bool f=1;
				for(int k=0;k<s1[p].size();k++){
					if(s1[p][k]!=t1[j+k]){
						f=0;
						break;
					}
				}
				if(f){
					for(int k=0;k<s1[p].size();k++){
						if(s2[p][k]!=t2[j+k]){
							f=0;
							break;
						}
					}
				}
				if(!f&&t1[j]!=t2[j]){
					flag=0;
					break;
				}
				if(f){
					j=j+s1[p].size();
					for(;j<t1.size();j++){
						if(t1[j]!=t2[j]){
							flag=0;
							break;
						}
					}
				}
				if(!flag)break;
			}
			if(flag)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
