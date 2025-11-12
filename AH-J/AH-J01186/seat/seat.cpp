#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,m,a[1000+10][1000+10];
vector<LL> v;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(LL i=1;i<=n*m;i++){
		LL x;
		cin>>x;
		v.push_back(x);
	}
	LL s=v[0];
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	LL minh=1,maxh=n,minl=1,indx=0;
	while(indx<n*m){
		for(LL i=minh;i<=maxh;i++)a[i][minl]=v[indx++];
		minl++;
		if(indx>=n*m)break;
		for(LL i=maxh;i>=minh;i--)a[i][minl]=v[indx++];
		minl++;
	}
	LL r,c;
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=m;j++){
			if(a[i][j]==s){r=i,c=j;}
		}
	}
	printf("%lld %lld",c,r);
	return 0;
}
