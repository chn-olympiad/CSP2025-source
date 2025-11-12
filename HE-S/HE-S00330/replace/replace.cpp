#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>inline void read(T&x){
	x=0; char c; int sign=1;
	do{c=getchar();if(c=='-') sign=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
	x*=sign;
}

int n,q;
string s[200010],s2[200010];
string str1,str2;


int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);read(q);
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s2[i];
	}
	while(q--){
		int l,x,pos,ans=0; string stn;
		cin>>str1>>str2;
		for(int i=1;i<=n;i++){
			if(str1.find(s[i])==-1) continue;
			l=0; x=s[i].size(); 
			
			while(str1.find(s[i],l)!=-1){
				pos=str1.find(s[i],l);
				l=pos+1; stn="";
				for(int j=1;j<=x;j++){ 
					stn=stn+str1[pos+j-1];
				}
				str1.erase(pos,x); str1.insert(pos,s2[i]);
				if(str1==str2){
					ans++;
				}
				str1.erase(pos,x); str1.insert(pos,stn);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
