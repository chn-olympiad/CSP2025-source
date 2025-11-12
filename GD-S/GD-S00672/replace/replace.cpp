#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int sum=0,x=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')x=-1;
		ch=getchar();
	}
	while(ch>='0'&&(ch<='9')){
		sum=(sum<<3)+(sum<<1)+(ch^48);
		ch=getchar();
	}
	return sum*x;
}
int n,q,st,en,ans;
string a,b,xa[300010],xb[300010],tk,tsk,k,sk;
unordered_map<string,vector<string> >mp;
inline string S(int s,int e){
	string sk="";
	for(int i=s;i<=e;i++)sk+=a[i];
	return sk;
}
inline string SS(int s,int e){
	string sk="";
	for(int i=s;i<=e;i++)sk+=b[i];
	return sk;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++){
		cin>>xa[i]>>xb[i];
		mp[xa[i]].emplace_back(xb[i]);
	}
	for(int xq=1;xq<=q;xq++){
		cin>>a>>b;
		for(int i=0;i<(int)a.size();i++){
			if(a[i]!=b[i]){
				st=i;
				break;
			}
		}
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]!=b[i]){
				en=i;
				break;
			}
		}
		ans=0;
		for(int i=st;i>=0;i--){
			for(int j=max(st,en);j<(int)a.size();j++){
				if(j<i)continue;
				tk=S(i,j);tsk=SS(i,j);
				for(string sl:mp[tk]){
					if(sl==tsk){
						ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//wjh
