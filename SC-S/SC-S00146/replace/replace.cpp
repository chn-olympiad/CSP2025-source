#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
string s1[100000],s2[100000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int T=0;T<q;T++){
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		if(t1.size()==t2.size()){
			for(int i=0;i<t1.size();i++){
				for(int j=0;j<n;j++){
					if(t1[i]==s1[j][0]){
						bool f=false;
						for(int k=1;k<s1[j].size();k++){
							if(t1[i+k]!=s1[j][k])f=true;
						}
						if(!f){
							string ns=t1;
							for(int k=0;k<t1.size();k++){
								if(k>=i&&k<i+s1[j].size())ns[k]=s2[j][k-i];
							}
							//cout<<j<<ns<<" "<<t2<<"\n";
							if(ns==t2)ans++;
						}
					}
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}