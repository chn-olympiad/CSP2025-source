#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define N 1005
int n,m;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	int s = a[1];
	sort(a+1,a+n*m+1);
	int cnt = 1;
	for(int i = n*m;i>=1;i--,cnt++){
		if(a[i] == s)break;
	}
	int h;
	int l = int(ceil(cnt*1.0/n));
	int sum = 1;
	for(int j = 1;j<=m;j++){
		for(int i = (j%2 == 0 ? n:1);(j%2 == 0 ? i>=1:i<=n);(j%2 == 0 ? i--:i++),sum++){
			if(sum == cnt)h = i;
		}
	}
	cout<<l<<" "<<h;
	return 0;
	
}