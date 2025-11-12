#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct stu{
	ll score,number;
}a[105];
ll n,m;
bool cmp(stu a,stu b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) cin>>a[i].score,a[i].number=i;
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++) cout<<a[i].score<<"\n";
	for(ll i=1;i<=n*m;i++){
		if(a[i].number==1){
			ll x=(i-1)/m+1,y;
			if(x&1) y=(i-1)%n+1;
			else y=n-(i-1)%n;
			cout<<x<<" "<<y;
			break;
		}
	}
	return 0;
}
