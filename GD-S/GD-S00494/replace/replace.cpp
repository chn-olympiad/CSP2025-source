#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s[200010][2],t1,t2,st1,st2;
map<string,string>ss;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	srand(time(0));
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		ss[s[i][0]]=s[i][1];
	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){cout<<"0\n";continue;}
		int len=t1.length(),k1=0,k2=len-1;
		while(t1[k1]==t2[k1])k1++;
		while(t1[k2]==t2[k2])k2--;
		for(int l=1;l<=len;l++)
			for(int i=0;i+l-1<len&&i<=k1;i++){
				if(i+l-1<k2)continue;
				st1=t1.substr(i,l);st2=t2.substr(i,l);
				if(ss.count(st1)&&ss[st1]==st2)ans++;
			}
		cout<<ans<<"\n";
	}
	return 0;
}

