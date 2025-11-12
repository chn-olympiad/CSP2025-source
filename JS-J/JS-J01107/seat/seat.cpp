#include<bits/stdc++.h>
using namespace std;
long long n,m,R;
long long mark[1005];
long long a[15][15];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>mark[i];
	}
	R=mark[1];
	sort(mark+1,mark+n*m+1,cmp);
	long long cnt=1;
	bool f=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(mark[cnt]==R){
					cout<<i<<' '<<j;
					f=0;
					break;
				}
				cnt++;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(mark[cnt]==R){
					cout<<i<<' '<<j;
					f=0;
					break;
				}
				cnt++;
			}
		}
		if(f==0){
			break;
		}
	}
	return 0;
}
