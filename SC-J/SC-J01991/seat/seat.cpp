#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int maxn=100;
int n,m,sum,k,cnt=0,li,ha,cnt1=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;sum=n*m;
	cin>>k;
	for(int i=2,x;i<=sum;i++){
		cin>>x;
		if(x>k) cnt++;
	}
//	li=ceil(1.0*cnt/n),ha=cnt%n;
//	if(ha==0) ha=n;
//	if(li%2==0) ha=n-ha+1;
//	cout<<li<<" "<<ha;
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++,cnt1++)
				if(cnt1==cnt){cout<<i<<" "<<j;return 0;}
		}else{
			for(int j=n;j>=1;j--,cnt1++)
				if(cnt1==cnt){cout<<i<<" "<<j;return 0;}
		}
	}
	return 0;
}//855
/*
3 4
9 1 2 3 4 5 6 7 8 10 11 12

*/