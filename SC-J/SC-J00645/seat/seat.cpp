#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;

int a[105];
/*
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
*/

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+1+n*m);
	int id=0;
	for(int i=1;i<=n;i++){
		if(x==a[i]){
			id=n*m-i+1;
			break;
		}
	}
	int l=(id+n-1)/n;
	if(l%2==1){
		cout<<l<<' '<<(id-1)%n+1;
	}else{
		cout<<l<<' '<<n-((id-1)%n+1)+1;
	}
	
	return 0;
} 
