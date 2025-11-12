#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,b=0,cnt=0,max,b1=0;
	cin>>n;
	int a[n+10];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		max=a[i]*2;
		b=a[i];
		b1=b+a[i+1];
		for(int j=n-1;j<i+1;j--){
			if((a[j]+b1)>max){
				cnt=j-(i+1)+cnt;
			}
			else
			continue;
		}
	}
	cout<<998244353%cnt;
	return 0;
}

