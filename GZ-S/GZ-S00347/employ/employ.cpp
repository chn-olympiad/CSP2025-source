//GZ-S00347 贵阳市华师一学校 田淑文
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int mod=998244353;
ll n,m,r,ans,num;
ll c[N],q[N],cnt,f[N];
string s;
ll work(ll x){
	if(x==0) return 0;
	ll sum=1;
	for(int i=1;i<=x;i++){
		sum=(sum*i)%mod;
	}
	return sum%mod;
}
int cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
cin>>n>>m;
cin>>s;
for(int i=0;i<n;i++){
	int t=s[i]-'0';
	q[i+1]=q[i]+t;
}
for(int i=1;i<=n;i++){
	cin>>c[i];
	r=n;
	for(int j=1;j<=n;j++){
		if(q[j]>=c[i]){
			r=j;
			break;
		}
	}
	if(r!=n) f[++cnt]=n-r;
	else f[++cnt]=0;
}
sort(f+1,f+cnt+1,cmp);
num=0;
for(int i=1;i<=n;i++){
	num=(num+work(f[i]))%mod;

}

ans=(work(n)-num)%mod;
cout<<ans<<endl;
	return 0;
} 

