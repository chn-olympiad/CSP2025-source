#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,pos=0;
	cin >> n >> m;
	pair<int,int> a[1005];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			pos++;
			cin>>a[pos].first;
			a[pos].second=pos;
		}
	}
	sort(a+1,a+pos+1);
	int cnt=0;
	for (int i=1;i<=pos;i++){
		if (a[i].second==1){
			cnt=pos-i+1;
			break;
		}
	}
	int x=cnt%n,y=(cnt+m-1)/m;
	cout << y << " "; 
	if (x==0)x=n;
	if(y%2==1)cout <<x;
	else cout << n-x+1;
	return 0;
}
