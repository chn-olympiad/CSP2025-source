#include<bits/stdc++.h>
using namespace std;
int n;
struct peo{
	pair<int,int> fir,sec;
}p[100005];
bool cmp(peo a,peo b){
	return (a.fir.first-a.sec.first)>(b.fir.first-b.sec.first);
}
int read(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=read();
//	cin>>T;
	while(T--){
		n=read();
//		cin>>n;
		int num[4];
		num[1]=num[2]=num[3]=0;
		for(int i=1;i<=n;i++){
			pair<int,int> a,b,c;
			a.first=read();b.first=read();c.first=read();
//			cin>>a.first>>b.first>>c.first;
			a.second=1;b.second=2;c.second=3;
			if(a<b) swap(a,b);
			if(b<c) swap(b,c);
			if(a<b) swap(a,b);
			p[i].fir=a;
			p[i].sec=b;
		}
		sort(p+1,p+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(num[p[i].fir.second]==(n>>1)){
				ans+=p[i].sec.first;
				num[p[i].sec.second]++;
			}else{
				ans+=p[i].fir.first;
				num[p[i].fir.second]++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
