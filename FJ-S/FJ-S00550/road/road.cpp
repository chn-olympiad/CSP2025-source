#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,head[10010],uq,vq,wq,cnt,minw,minu,minv,t[10010],ans;
struct gb{
	ll bq,bh;
	bool operator <(gb _) const{
		if(bq==_.bq) return bh>_.bh;
		return bq>_.bq;
	}
};
priority_queue<gb> q;
struct cb{
	ll nex,zd,qz,usop,qd;
}b[2001000];
void buil(ll qw,ll zw,ll dq){
	cnt++;
	b[cnt].nex=head[qw];
	head[qw]=cnt;
	b[cnt].qz=dq;
	b[cnt].zd=zw;
	b[cnt].qd=qw;
	return;
}
void adb(ll wz){
	for(int i=head[wz];i!=0;i=b[i].nex){
		gb jd;
		jd.bh=i;
		jd.bq=b[i].qz;
		if(b[i].usop!=1) q.push(jd);
	}
	return;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>uq>>vq>>wq;
		buil(uq,vq,wq);
		buil(vq,uq,wq);
		if(wq<minw){
			minw=wq;
			minu=uq;
			minv=vq;
		}
	}
	adb(minu);
	t[minu]=1;
	for(int i=1;i<=n-1;i++){
		gb jd;
		while(!q.empty()){
			jd=q.top();
			if(t[b[jd.bh].qd]==1&&t[b[jd.bh].zd]==1) q.pop();
			else break;
		}
		if(t[b[jd.bh].qd]==0) adb(b[jd.bh].qd);
		t[b[jd.bh].qd]=1;
		if(t[b[jd.bh].zd]==0) adb(b[jd.bh].zd);
		t[b[jd.bh].zd]=1;
		b[jd.bh].usop=1;
		ans+=b[jd.bh].qz;
	}
	cout<<ans<<endl;
	return 0;
} 
/*
3 3 0
1 2 3
2 3 3
1 3 1
*/
