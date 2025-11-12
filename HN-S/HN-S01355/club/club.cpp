#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int t,n
struct node{
	int g1,g2,g3;
}a[N];
bool cmp1(node a,node b){return a.g1 > b.g1;}
bool cmp2(node a,node b){return a.g2 > b.g2;}
bool cmp3(node a,node b){return a.g3 > b.g3;}
int main () {
	froepen("club.in","r",stdin);
	froepen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i].g1 >> a[i].g2 >> a[i].g3;
		}
		sort(a+1,a+n+1,cmp1);
		sort(a+1,a+n+1,cmp2);
		sort(a+1,a+n+1,cmp3);
	}
	return 0;
}		
