#include <bits/stdc++.h>
using namespace std;
pair <int,int> lis[200];
bool cmp(pair <int,int> a,pair <int,int> b){return a.first>b.first;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m; cin >> n >> m;
	for(int i = 1;i <= n*m;i++){cin >> lis[i].first; lis[i].second=i;}
	sort(lis+1,lis+1+n*m,cmp);
	for(int i = 1;i <= n*m;i++){
		if(lis[i].second==1){
			cout << (i-1)/n+1 << ' ';
			if((i-1)/n%2==1) cout << n-((i-1)%n);
			else cout << (i-1)%n+1;
		}
	}
	return 0;
}
