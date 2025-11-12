#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int t,n;
int a[N],b[N],c[N],d[N];
int da[N],db[N],dc[N];
int query(int a,int b,int c){
	if(a>c) swap(a,c);
	if(b>c) swap(b,c);
	if(a>b) swap(a,b);
	return (c-b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		int cnt1=0,cnt2=0,cnt3=0;
		ll sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i] && a[i]>=c[i])da[++cnt1]=i,sum+=a[i];
			else if(b[i]>=a[i] && b[i]>=c[i])db[++cnt2]=i,sum+=b[i];
			else if(c[i]>=a[i] && c[i]>=b[i])dc[++cnt3]=i,sum+=c[i];
		}
		if(cnt1>n/2) {
			for(int i=1;i<=cnt1;i++)
				d[i]=query(a[da[i]],b[da[i]],c[da[i]]);
			sort(d+1,d+cnt1+1);
			for(int i=1;i<=cnt1-n/2;i++)
				sum-=d[i];
		}
		if(cnt2>n/2) {
			for(int i=1;i<=cnt2;i++)
				d[i]=query(a[db[i]],b[db[i]],c[db[i]]);
			sort(d+1,d+cnt2+1);
			for(int i=1;i<=cnt2-n/2;i++)
				sum-=d[i];
		}
		if(cnt3>n/2) {
			for(int i=1;i<=cnt3;i++)
				d[i]=query(a[dc[i]],b[dc[i]],c[dc[i]]);
			sort(d+1,d+cnt3+1);
			for(int i=1;i<=cnt3-n/2;i++)
				sum-=d[i];
		}
		cout<<sum<<"\n";
	}
	return 0;
}
