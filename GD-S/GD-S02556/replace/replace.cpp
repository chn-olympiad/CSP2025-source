#include<bits/stdc++.h>
using namespace std;
int n,q;
unordered_map<string,string>m;
string substr(string s,int a,int b){
	string s0="";
	for(int i=a;i<b;i++){
		s0+=s[i];
	}
	return s0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n<=100){
		for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		m[s1]=s2;
	}
	while (q--){
		string s1,s2;
		cin>>s1>>s2;
		long long int ans=0;
		for(int i=0;i<s1.size()+1;i++){
			for(int j=0;j<s1.size()+1;j++){
				string x=substr(s1,0,i);
				string y=substr(s1,j,s1.size());
				string z=substr(s1,i,j);
				if((x+m[z]+y)==s2)++ans;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	}
	else{
		while(q--)cout<<0<<endl;
		return 0;
	}

}
