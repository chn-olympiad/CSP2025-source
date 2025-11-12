#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans,n,m,cnt,w1,w2,flag,cha[200005];
string d1,d2,t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d1>>d2;
		if(!flag){
			for(int j=0;j<d1.size();j++)
				if((int)d1[j]=='b'){w1=j;break;}
			for(int j=0;j<d2.size();j++)
				if((int)d2[j]=='b'){w2=j;break;}
			cha[i]=w1-w2;
		}
	}
	for(int i=0;i<d1.size();i++){
		if((int)d1[i]!='a'&&(int)d1[i]!='b'){flag=1;break;}
		if((int)d1[i]=='b') cnt++;
		if(cnt>1){flag=1;break;}
	}
	for(int i=1;i<=m;i++){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){cout<<0<<"\n";continue;}
		if(!flag){
			for(int j=0;j<t1.size();j++)
				if((int)t1[j]=='b'){w1=j;break;}
			for(int j=0;j<t2.size();j++)
				if((int)t2[j]=='b'){w2=j;break;}
			for(int j=1;j<=n;j++){
				if(cha[j]==w1-w2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

