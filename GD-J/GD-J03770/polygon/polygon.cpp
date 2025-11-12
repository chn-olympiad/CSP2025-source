#include <bits/stdc++.h>
using namespace std;
int n,a[5005],cnt,rem[5005];
bool vis[5005];
void dfs(int k,int al,int sum,int no){
	if(k==0){
		int maxn = -1;
		for (int i =1;i <=al;i++){
			maxn = max(maxn,rem[i]);
			rem[i] = 0;
		}
		if(sum >2*maxn) cnt++;
		return;
	}
	if(no > n) return;
	rem[al-k+1] = a[no];
	dfs(k-1,al,sum+a[no],no+1);
	rem[al-k+1] = 0;
	dfs(k,al,sum,no+1);
}
int main(){
	cin >> n;
	for (int i =1;i <= n;i++) cin >> a[i];
	for (int i =3;i <= n;i++)
	{
		dfs(i,i,0,1);	
	}
	cout << cnt%998244353;
	return 0;
} 
