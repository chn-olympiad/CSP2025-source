#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
const int N=3e3+6,M=2e6+6;
string x[N],y[N];int len1[N],len2[N];
int o[N];
map<int,int> mp; 
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	int sumlen=0;
	f(i,1,n){
		cin>>x[i]>>y[i];len1[i]=x[i].size();len2[i]=y[i].size();
		sumlen+=x[i].size();
	}
	if(sumlen>2000){
		f(i,1,n){
			int id1=x[i].find('b');int id2=y[i].find('b');
			mp[id1-id2]++;
		} 
		while(q--){
			string a,b;cin>>a>>b;
			int id1=a.find('b');int id2=b.find('b');
			cout<<mp[id1-id2]<<"\n";
		} 
		return 0;
	} 
	while(q--){
		string a,b;cin>>a>>b;int len=a.size()-1;
		int l=-1,r=-1;int ans=0;
		f(i,0,len){
			if(a[i]!=b[i]&&l==-1){l=i;continue;} 
			if(a[i]!=b[i]){r=i;}
		}
		if(l==-1&&r==-1)l=0,r=a.size();
		f(i,r,len){
			f(j,1,n){
				if(i-(len1[j])+1<=l&&i-(len1[j])+1>=0){
					if(a.substr(i-x[j].size()+1,x[j].size())==x[j]&&b.substr(i-x[j].size()+1,x[j].size())==y[j])ans++;
					
				}
			} 
		}
		cout<<ans<<"\n";
	}
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
&&b.substr(i-x[j].size()+1,x[j].size())==y[j]
*/