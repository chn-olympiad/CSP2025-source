#include<bits/stdc++.h>
using namespace std;
int a[5005];
int n,ans=0,sum=0;
bool cmp(int X,int Y){
	return X>Y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[i]=x;
		sum+=x;
	}
	sort(a+1,a+n+1,cmp);
	if(n<3)cout<<0;
	else {
		if(a[1]>=a[2]+a[3])cout<<0;
		else cout<<1;
	}
	
	return 0;
} 
