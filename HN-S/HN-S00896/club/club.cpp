#include <bits/stdc++.h>
using namespace std;
int t,n,a[4][100005];
bool cmp(int x,int y){
	return x > y;
}
int maxj(int n){
	for(int j = 1;j <= 3;j++){
		for(int i = 1;i <= n;i++)
			a[j][i] = -1;
	}
	for(int j = 1;j <= 3;j++){
		for(int i = 1;i <= n;i++)
			cin >> a[j][i];
	}
	int maxl[4],sumz = 0;
	for(int i = 1;i <= 3;i++) maxl[i]=0;
	for(int j = 1;j <= 3;j++){
		for(int i = 1;i <= n/2;i++){
			sort(a[j]+1,a[j]+n+1,cmp);
			maxl[j]+=a[j][i];
			for(int b = 1;b <= 3;b++) a[b][i] = 0;
		}
	}
	for(int j = 1;j <= 3;j++) sumz += maxl[j];
	return sumz;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n;
		cout << maxj(n) << endl;
	}
	return 0;
}
