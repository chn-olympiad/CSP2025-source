#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 500005
#define M 1005
using namespace std;
int a[N];
bool vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	int n,k;
	cin>>n>>k;
	int maxn = -2e9;
	int minn = 2e9;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		maxn = max(maxn, a[i]);
		minn = min(minn, a[i]);
	}
//	else if(n <= 10 && k <= 1 && maxn == 1 && minn == 0){
//		int a_0 = 0, a_1 = 0;
//		for(int i = 1; i <= n; i++){
//			if(a[i]==0){
//				a_0+=1; 
//			}
//			else if(a[i]==1){
//				a_1+=1; 
//			}
//		}
//		if(k==0){
//			
//		}
//	}
	if(n <= 100 && k == 0 && maxn == 1 && minn == 1){
		cout<<n/2;
		return 0;
	}
	
	return 0;
} 
