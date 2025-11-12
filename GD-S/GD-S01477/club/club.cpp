#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0;char ch='?';
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+(ch-'0'),ch=getchar();
	return x;
}
int n,id,a[100005][4],b[100005],c[100005],tot;
int cnt[4];
long long ans;
void solve(){
	ans=id=tot=cnt[1]=cnt[2]=cnt[3]=0;
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)a[i][j]=read();
		b[i]=max(a[i][1],max(a[i][2],a[i][3]));
		ans+=b[i];
		for(int j=1;j<=3;j++)
			if(a[i][j]==b[i]){
				cnt[j]++;
				c[i]=j;
				break;
			}
	}
	for(int i=1;i<=3;i++)
		if(cnt[i]>n/2)id=i;
	if(id==0)cout<<ans<<'\n';
	else{
		for(int i=1;i<=n;i++)
			if(c[i]==id){
				tot++;
				if(id==1)b[tot]=a[i][1]-max(a[i][2],a[i][3]);
				if(id==2)b[tot]=a[i][2]-max(a[i][1],a[i][3]);
				if(id==3)b[tot]=a[i][3]-max(a[i][1],a[i][2]);
			}
		sort(b+1,b+tot+1);
		for(int i=1;i<=tot-n/2;i++)ans-=b[i];
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;while(T--)solve();
	return 0;
}
