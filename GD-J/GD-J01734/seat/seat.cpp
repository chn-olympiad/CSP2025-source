#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int k;
			cin>>k;
			if(i==1&&j==1) a=k;
			else if(k>a) cnt++;
		}
	}
	cout<<(cnt-1)/n+1<<' '<<(((cnt-1)/n+1)%2==0?n+1-(cnt-n*((cnt-1)/n)):(cnt-n*((cnt-1)/n)));
	return 0;
}
