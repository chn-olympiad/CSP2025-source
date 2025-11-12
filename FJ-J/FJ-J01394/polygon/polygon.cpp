#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,flag,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		flag+=a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			sum+=a[j];
			if(sum>flag)cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
