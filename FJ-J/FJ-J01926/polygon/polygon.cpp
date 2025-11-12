#include<bits/stdc++.h>
using namespace std;
int sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//ios::_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,t[5005];
	int a[5005];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i==1) t[1]=a[1];	
		if(i>1) t[i]=t[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int h=t[j]-t[i-1];
		}
	}

	return 0;
} 

