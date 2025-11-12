//I Love CCF.I Want 100pts in this problem!
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
void read(ll &x){
	x=0;ll f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=f;
}
const int N=1e5+2;
struct node{
	int a,ida;//yi xuan she tuan de man yi du he yi xuan she tuan de bian hao
	int b,idb;//er xuan
	int c,idc;//san xuan
	int idn;//xuan de shi ji xuan she tuan
}st[N];
int t,n,x[3][N],tot[3];
bool cmp(int x,int y){
	return st[x].a-st[x].b>st[y].a-st[y].b;//cong da dao xiao pai xu
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--){
		tot[0]=tot[1]=tot[2]=0;
		read(n);
		for(int i=1;i<=n;i++){
			int u[3];read(u[0]),read(u[1]),read(u[2]);
			int mx=max(u[0],max(u[1],u[2]));int idmx=-1;
			int mn=min(u[0],min(u[1],u[2]));int idmn=-1;
			for(int j=0;j<3;j++){
				if(u[j]==mx and idmx==-1) st[i].a=u[j],st[i].ida=j,idmx=j;
				else if(u[j]==mn and idmn==-1) st[i].c=u[j],st[i].idc=j,idmn=j;
				else st[i].b=u[j],st[i].idb=j;
			}
			st[i].idn=1;
		}
		for(int i=1;i<=n;i++) x[st[i].ida][++tot[st[i].ida]]=i;
		int num=n/2;
		if(tot[0]>num){
			//int now=tot[0]-num;
			sort(x[0]+1,x[0]+tot[0]+1,cmp);
			for(;tot[0]>num;){
				int idx=x[0][tot[0]--];
				x[st[idx].idb][++tot[st[idx].idb]]=idx;
				st[idx].idn=2;
			}
		}
		else if(tot[1]>num){
			//int now=tot[1]-num;
			sort(x[1]+1,x[1]+tot[1]+1,cmp);
			for(;tot[1]>num;){
				int idx=x[1][tot[1]--];
				x[st[idx].idb][++tot[st[idx].idb]]=idx;
				st[idx].idn=2;
			}
		}
		else if(tot[2]>num){
			//int now=tot[2]-num;
			sort(x[2]+1,x[2]+tot[2]+1,cmp);
			for(;tot[2]>num;){
				int idx=x[2][tot[2]--];
				x[st[idx].idb][++tot[st[idx].idb]]=idx;
				st[idx].idn=2;
			}
		}
		//cout<<num<<'\n';
		//cout<<tot[0]<<" "<<tot[1]<<" "<<tot[2]<<'\n';
		//for(int i=1;i<=tot[0];i++) cout<<x[0][i]<<' ';
		//cout<<'\n';
		//for(int i=1;i<=tot[1];i++) cout<<x[1][i]<<' ';
		//cout<<'\n';
		//for(int i=1;i<=tot[2];i++) cout<<x[2][i]<<' ';
		//cout<<'\n';
		ll ans=0;
		for(int i=1;i<=tot[0];i++){
			int idx=x[0][i];
			//cout<<idx<<" ";
			if(st[idx].idn==1) ans+=st[idx].a;
			else ans+=st[idx].b;
		}
		//cout<<'\n';
		for(int i=1;i<=tot[1];i++){
			int idx=x[1][i];
			//cout<<idx<<" ";
			if(st[idx].idn==1) ans+=st[idx].a;
			else ans+=st[idx].b;
		}
		//cout<<'\n';
		for(int i=1;i<=tot[2];i++){
			int idx=x[2][i];
			if(st[idx].idn==1) ans+=st[idx].a;
			else ans+=st[idx].b;
			//cout<<idx<<" ";
		}
		//cout<<'\n';
		printf("%lld\n",ans);
	}
	return 0;
}
//I only have 172pts,can i go to NOIP(sad)?i want to go it!
//my names in Luogu is JadeFox2012
