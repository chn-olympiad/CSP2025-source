#include <bits/stdc++.h>
#define fis first
#define sec second
using namespace std;
const int znd=1000000;
int T,n,cnt[11],a[111111][11],stat[111111];
long long ans;
priority_queue<pair<int,int>>q;
void phase1(){
	for(int i=1;i<=n;i++){
		ans+=a[i][1];
		stat[i]=1;
	}
	cnt[1]=n;
	return;
}
void phase2(){
	while(q.size()){
		q.pop();
	}
	for(int i=1;i<=n;i++){
		q.push({a[i][2]-a[i][1],i});
	}
	while(cnt[2]<n/2){
		int now=q.top().sec,w=q.top().fis;
		if(w<0){
			break;
		}
		q.pop();
		ans+=w;
		++cnt[2],--cnt[1];
		stat[now]=2;
	}
//	for(int i=1;i<=n;i++){
//		cout<<stat[i]<<' ';
//	}
//	cout<<"\n";
	return;
}
void phase3(){
	while(q.size()){
		q.pop();
	}
	for(int i=1;i<=n;i++){
		q.push({a[i][3]-a[i][stat[i]],i});
	}
	while(cnt[3]<n/2){
		int now=q.top().sec,w=q.top().fis;
		if(w<0){
			break;
		}
		q.pop();
		ans+=w;
		++cnt[3],--cnt[stat[now]];
		stat[now]=3;
	}
//	for(int i=1;i<=n;i++){
//		cout<<stat[i]<<' ';
//	}
//	cout<<"\n";
	return;
}
void phase4(){
	while(q.size()){
		q.pop();
	}
	for(int i=1;i<=n;i++){
		if(stat[i]==1){
			q.push({a[i][2]-a[i][stat[i]],i+2*znd});
			q.push({a[i][3]-a[i][stat[i]],i+3*znd});
		}
	}
//	cout<<'\n';
	while(cnt[2]<n/2&&cnt[3]<n/2){
		int now=q.top().sec,w=q.top().fis;
		q.pop();
		if(stat[now%znd]!=1){
			continue;
		}
		if(cnt[1]<=n/2&&w<0){
			break;
		}
//		cout<<now%znd<<':'<<stat[now%znd]<<"->"<<now/znd<<','<<a[now%znd][stat[now%znd]]<<"->"<<a[now%znd][now/znd]<<'\n';
		ans+=w;
		++cnt[now/znd],--cnt[stat[now%znd]];
		stat[now%znd]=now/znd;
	}
//	for(int i=1;i<=n;i++){
//		cout<<stat[i]<<' ';
//	}
//	cout<<"\n";
	return;
}
bool ts=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	if(ts){
		freopen("club5.in","r",stdin);
	}
	else{
		freopen("club.in","r",stdin);
	}
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		phase1();
		phase2();
		phase3();
		phase4();
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			a[i][1]=a[i][2]=a[i][3]=stat[i]=0;
		}
	}
	return 0;
}
