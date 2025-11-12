#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cnt(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int aaa=a[1];
	int len=0;
	sort(a+1,a+1+m*n,cnt);
	for(int i=1;i<=n*m;i++){
		if(a[i]==aaa){
			len=i;
			break;
		}
	}
	int he=len/(n*2);
	int mu=len%(n*2);
	if(mu==0){
		he--;
		mu=n*2;
	}
//	cout<<he<<" "<<mu<<"\n";
	if(mu<=n){
		cout<<he*2+1<<" "<<mu;
	}
	else{
		cout<<he*2+2<<" "<<2*n-mu+1;
	}
	return 0;
}
/*
5 2
1 100 99 98 97 96 95 94 93 92

2 1
*/

