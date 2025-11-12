#include<bits/stdc++.h>
using namespace std;
map<string,string> m;
map<int,int>b;
int n,t,num[5000005],x[200005];
string s[200005],s0[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s0[i];
	}
	while(t--){
		string l1,l2;
		cin>>l1>>l2;
		string ss="";
		int coun=0;
		for(int i=0;i<l1.size();i++){
			for(int j=1;j<=n;j++){
				string l=l1.substr(i,s[j].size());
				string sss=ss;
				if(l==s[j]) {
					for(int k=i;k<i+s[j].size();k++){
						sss[k]=s0[j][k-i];
					}
					for(int k=i+s[j].size();k<l1.size();k++){
						sss[k]=l1[k];
					}
				} 
				if(sss==l2) coun++;
			}
			ss=ss+s[i];
		}
		cout<<coun<<endl;
	}
	return 0;
}
