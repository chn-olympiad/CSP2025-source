#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll n,q,qd[10005],top2,zd[10005],top;
struct opzc{
	string x,y;
};
opzc a[10005],b[10005];
opzc sl[10005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>a[i].x>>a[i].y;
	for(int i=1;i<=q;++i){
		cin>>b[i].x>>b[i].y;
		top=0;
		memset(qd,0,sizeof qd);
		memset(zd,0,sizeof zd);
		ll ans=0;
		ll len=b[i].x.size();
		for(int j=0;j<len;++j){
			if(b[i].x[j]!=b[i].y[j]&&(zd[top]!=0||top==0)){
				qd[++top]=j;
			}else if(b[i].x[j]==b[i].y[j]){
				zd[top]=j-1;
			}
		}
		if(zd[top]==0)zd[top]=len-1;
		for(int k=1;k<=top;++k){
			sl[k].x=sl[k].y="";
			for(int j=qd[k];j<=zd[k];++j){
				sl[k].y+=b[i].y[j];
				sl[k].x+=b[i].x[j];
			}
		}
		for(int k=1;k<=top;++k){
			for(int j=1;j<=n;++j){
				if(sl[k].y==a[j].y&&sl[k].x==a[j].x){
					ans++;
					break;
				}
			}
		}
		for(int j=1;j<=n;++j){
			if(b[i].y==a[j].y&&b[i].x==a[j].x){
				ans++;
				break;
			}
		}
		cout<<ans<<"\n";
	}




	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/

