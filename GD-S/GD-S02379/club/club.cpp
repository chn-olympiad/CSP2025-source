#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005][3],b[100005],t[3],p[100005],s,ans;
void chk(int&x,int*a){
	for(int i=0;i<3;i++) if(a[i]>a[x]) x=i;
}
void Genshin_Impact(){
	cin>>n,ans=m=0;
	for(int i=1;i<=n;i++) for(int j=0;j<3;j++) scanf("%d",&a[i][j]);
	t[0]=t[1]=t[2]=0;
	for(int i=1;i<=n;i++) chk(p[i],a[i]),t[p[i]]++,ans+=a[i][p[i]];
	chk(s,t);
	for(int i=1;i<=n;i++) if(p[i]==s) b[++m]=a[i][p[i]]-max(a[i][(p[i]+1)%3],a[i][(p[i]+2)%3]);
	sort(b+1,b+m+1);
	for(int i=1;i<=t[s]-n/2;i++) ans-=b[i];
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club.in","w",stdout);
//	froepen("club.out","r",stdout);
//	freopen("club1.in","w",stdin);
//	freopen("club1.out","r",stdin);
	int T;
	cin>>T;
	while(T--) Genshin_Impact();
} 
