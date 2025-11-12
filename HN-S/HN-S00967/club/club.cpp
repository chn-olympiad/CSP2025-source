//club
#include<bits/stdc++.h>
using namespace std;
long long t,n,a1,a2,a3,m(0),sm[100005],s[4];
int xp(){
	if(max(max(a1,a2),a3)==a1)return 1;
	if(max(max(a1,a2),a3)==a2)return 2;
	if(max(max(a1,a2),a3)==a3)return 3;
}
int xf(int a,int b,int c){
	int ww=max(max(a,b),c),ee(10e6),rr(10e6),tt(10e6);
	if(ww!=a)ee=ww-a;
	if(ww!=b)rr=ww-b;
	if(ww!=c)tt=ww-c;
	if(ww==a&&ww==b)ee=0;
	if(ww==a&&ww==c)ee=0;
	if(ww==b&&ww==c)ee=0;
	return min(min(ee,rr),tt);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		m=s[1]=s[2]=s[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a1>>a2>>a3;
			sm[i]=xf(a1,a2,a3);
			s[xp()]++;
			m+=max(max(a1,a2),a3);
		}
		sort(sm+1,sm+n+1);
		for(int i=1;i<=max(max(s[1],s[2]),s[3])-n/2;i++)m-=sm[i];
		for(int i=1;i<=n;i++)sm[i]=0;
		cout<<m<<'\n';
	}
	return 0;
}
