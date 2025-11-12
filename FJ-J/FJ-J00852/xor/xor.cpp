#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100005]={},ans=0,ansr=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j-i+1>k)continue;
			ans=a[i];
			for(int k=i+1;k<=j;k++){
				ans^=a[k];
			}
			ansr=max(ansr,ans);
		}
	}
	cout<<ansr;
	return 0;
}
