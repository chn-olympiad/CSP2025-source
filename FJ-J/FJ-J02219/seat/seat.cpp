#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,c,r,a[N],cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		//cout<<a[i]<<' '<<a[0]<<"\n";
		if(a[i]>a[0]) cnt++;
	}
	int me=a[0],mem=cnt/n,men;
	
	if(cnt%n) mem+=1;
	
	if(mem%2==0) men=n-cnt%n+1;
	else men=cnt%n!=0?cnt%n:n;
	cout<<mem<<' '<<men;
	//cout<<cnt;
}