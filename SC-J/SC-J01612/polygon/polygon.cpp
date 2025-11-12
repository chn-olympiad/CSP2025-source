#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[50001],pre[50001]={0},num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=a[i]+pre[i-1];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int p=j+1;p<=n;p++){
				if(pre[p]-pre[j]<a[p]*2) break;
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}