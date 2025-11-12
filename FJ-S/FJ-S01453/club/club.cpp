#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,a[N],b[N],c[N],d[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n;int ma=0,mb=0,mc=0,s=0;
		for(int i=1;i<=n;i++){
			int x,y,z;cin>>x>>y>>z;
			int u=max(x,max(y,z));s+=u;
			if(x==u)a[++ma]=x-y-z+min(y,z);
			else if(y==u)b[++mb]=y-x-z+min(x,z);
			else c[++mc]=z-x-y+min(x,y);
		}
		if(ma>n/2){sort(a+1,a+ma+1);for(int i=1;i<=ma-n/2;i++)s-=a[i];}
		else if(mb>n/2){sort(b+1,b+mb+1);for(int i=1;i<=mb-n/2;i++)s-=b[i];}
		else if(mc>n/2){sort(c+1,c+mc+1);for(int i=1;i<=mc-n/2;i++)s-=c[i];}
		cout<<s<<'\n';
	}
	return 0;
}
//freopen("club.in","w",stdin);
//freopen("club.out","r",stdout);
//freopen("club1.in","r",stdin);
//freopen("club.ans","w",stdout);
//froepen("club.in","r",stdin);
//feropen("club.out","w",stdout);
//frepoen("club.in","r",stdin);
//frepopen("club.out","w",stdout);
