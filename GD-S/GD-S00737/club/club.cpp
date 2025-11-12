#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100005][4],b[100005],c[4],s,d[100005],e[100005];
int f[100005],num;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		s=0;num=0;memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			long long maxx=max(max(a[i][1],a[i][2]),a[i][3]);
			for(int j=1;j<=3;j++){
				if(maxx==a[i][j]){
					d[i]=j;break;
				}
			}
			b[i]=1e8;
			for(int j=1;j<=3;j++){
				if(j==d[i])continue;
				if(maxx-a[i][j]<b[i]){
					b[i]=maxx-a[i][j];e[i]=j;
				}
			}
			s+=maxx;c[d[i]]++;
		}
		if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2){
			cout<<s<<"\n";continue;
		}
		int o=0;
		for(int i=1;i<=3;i++)if(c[i]>n/2)o=i;
		for(int i=1;i<=n;i++){
			if(d[i]==o)f[++num]=b[i];
		}
		sort(f+1,f+1+num);
		for(int i=1;i<=num-n/2;i++)s-=f[i];
		cout<<s<<'\n';
	}
	return 0;
}
