#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long sc[100005];
int r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;++i){
		cin>>sc[i];
	}
	r=sc[1];
	sort(sc+1,sc+n*m+1);
	for(int i=1;i<=n*m/2;++i){
		swap(sc[i],sc[n*m-i+1]);
	}
	for(int i=1;i<=m;++i){//列
		if(i%2==0){
			for(int j=n;j>=1;--j){//行
				if(sc[(i-1)*n+n-j+1]==r){
					cout<<i<<" "<<j;
				}
			}
		}else{
			for(int j=1;j<=n;++j){
				if(sc[(i-1)*n+j]==r){
					cout<<i<<" "<<j;
				}
			}
		}
	}
	return 0;
}