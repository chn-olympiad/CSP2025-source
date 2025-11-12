#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],b[N],c[N],pandin1=0,pandin2=0;
bool cmp(int q,int w){
	return q>w;
}
void is_a(){
	sort(a+1,a+n+1,cmp);
	int sum=0;
	for(int i=1;i<=n/2;i++)sum+=a[i];
	cout<<sum<<'\n';
	return;
}
struct club{
	int valu;
	int id;
};
bool cmp1(club q,club w){
	return q.valu>w.valu;
} 
void is_b(){
	int sum=0;
	club c[N]={};
	for(int i=1;i<=n;i++){
		c[i].valu=a[i]-b[i];
		c[i].id=i;
	}	
	sort(c+1,c+n+1,cmp1);
	for(int i=1;i<=n/2;i++){
		sum+=a[c[i].id];
	}
	for(int i=n/2+1;i<=n;i++){
		sum+=b[c[i].id];
	}
	cout<<sum<<'\n';
	return;
}
void is_another(){
	for(int i=1;i<=n;i++){
		int jxc=c[i]-a[i],jxy=c[i]-b[i];
		if(jxc<0&&jxy<0)continue;
		if(jxc>jxy){
			a[i]=c[i];
			c[i]=0;
		}
		else{
			b[i]=c[i];
			c[i]=0;
		}
	}
	is_b();
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		pandin1+=(b[i]==0);
		pandin2+=(c[i]==0);
	}
	if(pandin1==n&&pandin2==n){
		is_a();
		return;
	}
	else if(pandin2==n){
		is_b();
		return;
	}
	else {
		is_another();
		return;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
