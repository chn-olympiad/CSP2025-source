//GZ-S00418 贵阳市第十八中学 谷佳鸿 
#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int maxn=1e5+5;
map<int,int>cnt;
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int x1=0,x2=0;
		for(int i=0;i<s1.size();i++){
			if(s1[i]=='b')x1=i;
		}for(int i=0;i<s2.size();i++){
			if(s2[i]=='b')x2=i;
		}cnt[x2-x1]++;
	}while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int x1=0,x2=0;
		for(int i=0;i<t1.size();i++){
			if(t1[i]=='b')x1=i;
		}for(int i=0;i<t2.size();i++){
			if(t2[i]=='b')x2=i;
		}printf("%d",cnt[x2-x1]);
	}
	return 0;
}

