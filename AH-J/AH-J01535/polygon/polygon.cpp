#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],s[5005];
int cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(i==n&&j==1) continue;
			int num=n;
			if(i==n) num=j-1;
			if(s[n]-s[i]+s[j-1]>a[num]*2&&n-i+j-1>=3){
				cnt++;
			}
		}
	}
	if(s[n]>a[n]*2) cnt++;
	cout<<cnt<<endl;
	return 0;
}
