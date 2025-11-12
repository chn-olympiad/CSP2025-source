#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 10005
using namespace std;
int a[N];
int cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1; i <= n*m; i++){
		cin>>a[i];
		if(a[i] > a[1]){
			cnt++;
		}
	}
	cnt+=1;
	cout<<cnt<<endl;
	int now = a[1];
	if(cnt%n==0){
		int l = cnt/n;
		if(l%2==0){
			cout<<1<<" ";
			cout<<l<<" "<<1;
		}
		else if(l%2!=0){
			cout<<2<<" ";
			cout<<l<<" "<<n;
		}
	}
	else if(cnt%n!=0){
		int l = cnt/n+1;
		int h = cnt-n*(l-1);
		if(l%2==0){
			cout<<3<<" ";
			cout<<l<<" "<<m-h+1;
		}
		else if(l%2!=0){
			cout<<4<<" ";
			cout<<l<<" "<<h;
		}
	}
	
	return 0;
} 
