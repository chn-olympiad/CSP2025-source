#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100];
bool cmp(int x,int y){
	return x>y;
} 
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++){
		cin >> a[i];
	}
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int it=0;
	for(int i = 1;i<=n*m;i++){
		if(a[i]==R){
			it=i;
			break;
		}
	}
	int lie=(it-1)/m+1;
	int hangnum=(it-1)%m+1;
	int hang;
	if(lie%2) hang=hangnum;
	else hang=n+1-hangnum;
	cout << lie << ' ' << hang;
	return 0;
}