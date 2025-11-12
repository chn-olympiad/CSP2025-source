#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+100;
struct node{
	int fir,sec,tir;
}a[N];
bool cmp(node x,node y){
	return x.fir>y.fir;
}
bool cmp1(node x,node y){
	return x.sec>y.sec;
}
bool cmp2(node x,node y){
	return x.tir>y.tir;
}
void solve(){
	int n,sum=0,ma=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].fir>>a[i].sec>>a[i].tir;
		sum+=a[i].fir;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n/2;i++){
		sum-=a[i].fir;
		sum+=max(a[i].sec,a[i].tir);
	}
	ma=max(ma,sum);
	sum=0;
	for(int i=1;i<=n;i++)sum+=a[i].sec;
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=n/2;i++){
		sum-=a[i].sec;
		sum+=max(a[i].fir,a[i].tir);
	}
	ma=max(ma,sum);
	sum=0;
	for(int i=1;i<=n;i++)sum+=a[i].fir;
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<=n/2;i++){
		sum-=a[i].tir;
		sum+=max(a[i].sec,a[i].fir);
	}
	ma=max(ma,sum);
	cout<<ma<<"\n";
	for(int i=1;i<=n;i++){
		a[i].fir=a[i].sec=a[i].tir=0;
	}
}

signed main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0),cout.tie(0);
int t;
cin>>t;
while(t--){
solve();	
}
return 0;
}
