#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=2e5;
string s[maxn+5],t[maxn+5];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++){
		cin>>s[i]>>t[i];
	}
	while(q--){
		int ans=0;
		string str1,str2;
		cin>>str1>>str2;
		for(int i=1; i<=n; i++){
			int w=str1.find(s[i]);
			if(w==-1) continue;
			string s1=str1.substr(0,w);
			s1+=t[i];
			s1+=str1.substr(w+s[i].size(),str1.size()-w-s[i].size()+1);
//			cout<<"s1=="<<s1<<"\n";
			if(s1==str2) ans++;
		}
		cout<<ans<<"\n";
	}
	
	return 0; //expect: 10+(0~20)pts
}
