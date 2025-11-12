#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=2e5+47;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int l1=t1.size();
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<l1-s1[i].size();j++){
				string p="",s="";
				for(int k=j;k<=j+s1[i].size();k++){
					p+=s1[k];
				}
				if(p==s1[i]){
					string ss1="",ss2="";
					for(int k=0;k<j;k++)ss1+=t1[k];
					for(int k=j+s1[i].size()+1;k<=l1;k++)ss2+=t1[k];
					s+=ss1;
					s+=s2[i];
					s+=ss2;
				}
				if(s==t2)cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
