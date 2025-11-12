#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,pos,idx,c,r;
long long a[105];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			long long sum;
			cin>>sum;
			if(i==1&&j==1)pos=sum;
			a[++cnt]=sum;
		}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
		if(a[i]==pos){
			idx=i;
			break;
		}
	if(idx<=n)c=1;
	else c=(idx)/n+1;
	r=idx-(c-1)*n;
	if(c%2==0)r=n+1-r;
	cout<<c<<' '<<r;
	return 0;
}
