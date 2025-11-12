#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
bool cmp(int x,int y){
	return (x>=y);
}
int t,n,a[8][100005],ans[100005],visit[8],summ,maxa=0;
int solve(int dep){
	if (dep>n){
		int summ=0;
		for (int i=1;i<=n;i++) summ+=a[ans[i]][i];
		if (summ>maxa) maxa=summ;
		return 0;
	}
	for (int i=1;i<=3;i++){
		if (visit[i]<n/2){
			ans[dep]=i;
			visit[i]++;
			solve(dep+1);
			visit[i]--;
			ans[dep]=0;
		}
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		cin>>n;
		bool tsa=1,tsb=1;
		for (int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if (tsa&&a[2][i]!=0) tsa=0;
			if (tsa&&a[3][i]!=0) tsa=0;
		}
		summ=0;
		sort(a[1]+1,a[1]+n+1,cmp);
		if (tsa){
			for (int i=1;i<=n/2;i++) summ+=a[1][i];
			cout<<summ<<endl; 
		}
		maxa=0;
		solve(1);
		cout<<maxa<<endl;
	}
	return 0;
} 
