#include<bits/stdc++.h>
using namespace std;
int n,l[5005];
long long cnt;
void dfs(int di,int sum,int deep){
	for(int i=di+1;i<=n;i++){
		int li=l[i];
		if(deep<2){
			dfs(i,sum+li,deep+1);
		}
		else if(li*2<sum+li){
			cnt++;
			dfs(i,sum+li,deep+1);
		}else dfs(i,sum+li,deep+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> l[i];
	}
	sort(l+1,l+1+n);
	for(int i=1;i<=n-2;i++){
		dfs(i,l[i],1);
	}
	cnt%=998244353;
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
} 
