#include<bits/stdc++.h>
using namespace std;
int l(int a,int b){
	if(a>b)return 1;
	else return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0;
	cin>>n;
	int a[1000005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			int all=a[1]+a[i+1]+a[j];
			int maxn=max(a[1],a[i+1]);
			maxn=max(maxn,a[j]);
			if(l(all,maxn))num++;
		}
	}
	cout<<num;
	return 0;
}