#include<bits/stdc++.h>
using namespace std;
const int N=5010, MOD=998244353;
int a[N], res, n ,st[N];
void dfs(int m, int add, int max_num){
	if(add>max_num*2 && m>=3){
		res=(res+1)%MOD;
		return;
	}else{
		for(int i=1; i<=n; i++){
			if(st[i]==false){
				add+=a[i];
				max_num=max(max_num, a[i]);
				m++;
				st[i]=true;
				dfs(m, add, max_num);
				st[i]=false;
			}	
		}
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	dfs(0, 0, 1);
	cout<<res%MOD<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
