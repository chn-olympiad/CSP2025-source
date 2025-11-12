#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long cnt;
int a[5010];
int k[5010];
long long t[5010];
long long st(long long s){
	s=3;
	long long cntt=0,nn=t[s];
	if(s==1||s==2)return 1;
	for(int i=1;i<s;i++){
		cntt+=(nn/(t[i]*(t[s]/t[s-i])));
	}
	return cntt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)k[i]=k[i-1]+a[i];
	t[1]=1;
	for(int i=2;i<=5010;i++)t[i]=i*t[i-1];
	for(int i=3;i<=n;i++){
		int maxx=a[i],s=3,sk=2;
		while((i-sk>=1)&&((k[i]-k[i-sk])<=(2*maxx)))s++,sk++;
		if((k[i]-k[i-sk])<=(2*maxx))continue;
		else{
			cnt+=st(i-sk);
			cnt%=998244353;
		}
	}
	cout<<cnt<<endl;
	return 0;
}