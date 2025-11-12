#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,t,cnt,p[110];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>p[i];
	}
	t=p[1];
	sort(p+1,p+n*m+1,cmp);
	for(int i=1;i<=n;++i){
		if(i%2==1){
			for(int j=1;j<=m;++j){
				++cnt;
				if(p[cnt]==t){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=m;j>=1;--j){
				++cnt;
				if(p[cnt]==t){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
