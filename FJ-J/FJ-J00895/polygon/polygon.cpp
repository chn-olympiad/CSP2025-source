#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<math.h>
using namespace std;
int n;
int a[5005];
//bool used[5005];
//int ans[5005],t=0;
int cnt=0;
//void dfs(int x,int y){
//	if(x==0){
//		int maxn=-1;
//		int count=0;
//		for(int i=1;i<=t;i++){
//			maxn=max(maxn,a[i]);
//			count+=a[i];
//		}
//		if( (count-maxn)>maxn )cnt++;
//	}
//	for(int i=y;i<=n;i++){
//		if(used[i]==false){
//			ans[++t]=i;
//			used[i]=true;
//			dfs(x-1,i+1);
//			used[i]=false;
//			t--;
//		}
//
//	}
//}
void pd(int l,int r)
{
	int maxn=-1;
	int count=0;
	for(int i=l;i<=r;i++){
		maxn=max(maxn,a[i]);
		count+=a[i];
	}
	if( (count-maxn)>maxn )cnt++;
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
		return 0;
	}
	for(int i=2;i<n;i++){
		for(int j=1;j<=n-i;j++){
			pd(j,j+i);
		}
	}
//	for(int i=5;i<=n;i++){
//		dfs(i,1)
//	}
	cout<<cnt<<endl;
	return 0;
}

