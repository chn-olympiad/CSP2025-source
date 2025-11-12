#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],now,tr[N][23],top,r,ans;
deque<int> q[N];
void update(int x,int id){
	int p=0;
	for(int i=20;i>=0;i--){
		int num=(x>>i)&1;
		if(!tr[p][num]) tr[p][num]=++top;
		p=tr[p][num];
	}
	q[p].push_front(id);
	return ;
}
void query(int x,int id){
	int p=0,op=0;
	for(int i=20;i>=0&&op!=-1;i--){
		int num=(x>>i)&1;
		if(!tr[p][num]) op=-1;
		else p=tr[p][num];
	}
	if(op==-1) return ;
	if(q[p].empty()) return ;
 	op=q[p].front();
	//cout<<op<<" "<<id<<" "<<x<<" "<<now<<"\n";
	if(op>=r){
		r=id;
		q[p].pop_front();
		ans++;
	}
	return ;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	update(now,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		now^=a[i];
		//cout<<i<<" "<<now<<" "<<(now^k)<<" "<<r<<"\n";
		query(now^k,i);
		update(now,i);
	}
	cout<<ans;
	return 0;
}

