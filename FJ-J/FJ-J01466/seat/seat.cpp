#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int x,y,cnt=0;
	cin >> x;
	for(int i = 2; i<=n*m; i++){
		cin >> y;
		if(y>x) cnt++;
	}
	cnt++;
	int sum=ceil(1.0*cnt/n);
	cout << sum << " ";
	cnt%=n;
	if(cnt==0){
		cout << n;
	}
	else if(sum%2==0){
		cout << m-cnt+1;
	}
	else{
		cout << cnt;
	}
	return 0;
}
