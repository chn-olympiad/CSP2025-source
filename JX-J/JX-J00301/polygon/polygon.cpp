#include <bits/stdc++.h>
using namespace std;
long long cnt;
int n,a[5005];
void dfs(int i1,int j1){
	if(n-i1<2){
		cout<<cnt;
		exit(0);
	}
	int qwq=-1,sum=0;
	for(int o=i1+1;o<j1;o++){
		qwq=-1;
		sum=0;
		for(int i=i1;i<=j1;i++){
			if(a[i]>qwq) qwq=a[i];
			sum+=a[i];
		}
		if(sum-a[o]>qwq*2) cnt++;
	}
	if(sum>qwq*2) cnt++;
	if(j1==n) dfs(i1+1,i1+3);
	else dfs(i1,j1+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,3);
	return 0;
}
