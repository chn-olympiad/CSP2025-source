#include<bits/stdc++.h>
using namespace std;
bool fangwen[5007][5007];//fangwen[i][j]表示第i层在此节点是否访问过
int a[5007];
long long n, ans1, ans, sss[5007];
int dfs(int num, int x){
	if(x>=num){
		int sum=0, maxn=0;
		for(int i=0; i<num; i++){
			sum+=sss[i];
			if(sss[i]>maxn)maxn=sss[i];
		}
		if(sum>=(maxn*2)){
			ans+=ans1;
		}
		ans1=0;
	} 
	for(int i=x; i<=n-(num-x); i++) {
		if(fangwen[x][i]){
			continue;
		}
		ans1+=a[i];
		fangwen[x][i]=true;
		sss[x]=a[i];
		ans += dfs(num, x+1);
	}
	return ans;
}
int main(){
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	if(n<=2){cout<<0;return 0;}
	for(int i=2; i<n; i++){//循环每一个小木棍的数量
		for(int j=i; j<n; j++){//循环起始下标
			for(int k=0; k<=i; k++){
				for(int l=0; l<=5007; l++){
					fangwen[k][l]=false;
				}
			}
			ans1=0;
			ans+=dfs(i+1, 0);
		}
		cout << endl;
	}
	cout<<ans;
	return 0;
} 

/*#include<iostream>
int main(){
	int n, n2;
	cin>>n2;
	n=n2; 
	for(int i=0; i<n2;i++)cin>>n;
	std::cout<<9;
	return 0;
}*/
