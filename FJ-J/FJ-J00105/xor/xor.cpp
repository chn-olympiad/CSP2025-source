#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
struct yh{
	long long s1;
	long long s2;
};
yh b[500005];
bool cmp(yh a,yh b){
	return a.s2<b.s2;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0,ans=0;
	for(int i=1;i<=n;i++){
		sum=sum^a[i];
		if(sum==m){
			ans++;
			b[ans].s1=i;
			b[ans].s2=i;
		}
		for(int j=i+1;j<=n;j++){
			sum=sum^a[j];
			if(sum==m){
				ans++;
				b[ans].s1=i;
				b[ans].s2=j;
			}
		}
		sum=0;
	}
	sort(b+1,b+ans+1,cmp);
	int l;
	int cnt=1;
	l=b[1].s2;
	for(int i=2;i<=n;i++){
		if(b[i].s1>l){
			cnt++;
			l=b[i].s2;
		}
	}
	cout<<cnt;
	return 0;
}
