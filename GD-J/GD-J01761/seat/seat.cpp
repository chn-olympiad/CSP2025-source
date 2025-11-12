#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+10;
string s;
int a[maxn];
pair<int,int> st[maxn];
int tot;
int n,m;
bool cmp(const int &a,const int &b){
	return a>b;
}
int p;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		scanf("%lld",&a[i]);
		if(i==1) p=a[i];
	}
	for(int j = 1;j <= m;j++){
		if(j%2==1){
			for(int i = 1;i <= n;i++){
				st[++tot]=make_pair(j,i);
			}
		}else{
			for(int i = n;i >= 1;i--){
				st[++tot]=make_pair(j,i);
			}
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++){
//		cout << st[i].first << " " << st[i].second << endl;
		if(a[i]==p){
			cout << st[i].first << " " << st[i].second;
			exit(0);
		}
//		cout << a[i] << endl;
	}
	
	return 0;
} 
