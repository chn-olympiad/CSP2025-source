#include<bits/stdc++.h> 
using namespace std;
//dp
#define int long long
#define accept 0
int n,k;
int a[500005],ans;
struct node{
	int a;
	int b;
};
vector<node> e;
bool cmp(node a,node b){
	return a.b < b.b;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k ;
	for(int i = 1;i <= n ;i++){
		cin >> a[i];
	}
	for(int i =1;i <= n ;i ++){
		int x = 0;
		for(int j = i;j <= n;j++){
			x ^= a[j];
			if(x == k){
				node q;
				q.a = i;
				q.b = j;
				e.push_back(q);
				break;
			}
		}
	}
	sort(e.begin(),e.end(),cmp);
	int lst = 0;
	for(int i =0;i <= e.size() ;i ++){
		if(e[i].a > lst){
			ans++;
			lst = e[i].b;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return accept;
}
