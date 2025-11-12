#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){return x > y;}
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m;
	cin >> n >> m;//m lie n hang 
	int mn = n * m;
	int a[105];
	for(int i = 0;i < mn;++i)cin >> a[i];
	
	int ap = a[0];
	int app = 0;
	sort(a,a + mn,cmp);
	for(int i = 1;i <= m;++i){
		if(i & 1){
			for(int j = 1;j <= n;++j){
				if(a[app] == ap){cout << i << " " << j;return 0;}
				app++;
				}
			}
		else{
			for(int j = n;j > 0;--j){
				if(a[app] == ap){cout << i << " " << j;return 0;}
				app++;
				}
			}
	}
	return 0;
}
