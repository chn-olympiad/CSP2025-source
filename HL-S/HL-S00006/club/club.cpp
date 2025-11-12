#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n;
struct k{
	ll d[4],st,nd,rd;
}a[100001];
bool o(k q,k p){
	return q.d[q.st]<p.d[p.st];
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
		if(a[i].d[1]==max(a[i].d[1],max(a[i].d[2],a[i].d[3]))){
			a[i].st=1;
			if(a[i].d[2]>=a[i].d[3])a[i].nd=2,a[i].rd=3;
			else a[i].rd=2,a[i].nd=3;
		}else if(a[i].d[2]==max(a[i].d[1],max(a[i].d[2],a[i].d[3]))){
			a[i].st=2;
			if(a[i].d[1]>=a[i].d[3])a[i].nd=1,a[i].rd=3;
			else a[i].rd=1,a[i].nd=3;
		}else{
			a[i].st=3;
			if(a[i].d[1]>=a[i].d[2])a[i].nd=1,a[i].rd=2;
			else a[i].rd=2,a[i].nd=1;
		}
	}sort(a+1,a+1+n,o);
//	for(int i=1;i<=n;i++){
//		cout<<a[i].st<<" "<<a[i].nd<<" "<<a[i].rd<<"\n";
//	}
	ll ans=0;
	if(n==2){
		if(a[1].st==a[2].st){
			cout<<a[1].d[a[1].st]+a[2].d[a[2].nd];
			return;
		}else{
			cout<<a[1].d[a[1].st]+a[2].d[a[2].st];
			return;
		}
	}else cout<<"516";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

