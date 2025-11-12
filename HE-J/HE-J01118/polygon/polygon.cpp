#include<bits/stdc++.h>
using namespace std;
int n,a[5001],sum=0;
int f(int x,int y){
	int zd=-1,zh=0;
	for(int i=x;i<=y;i++){
		zh+=a[i];
		zd=max(zd,a[i]);
		if(zh>zd*2){
			sum++;
			sum%=998244353;
		}
	}
	if(y!=n){
		return f(x,y+1);
	}
	else if(x!=n-2){
		return f(x+1,y);
	}
	else if(x==n-2&&y==n){
		return 0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(1,3);
	cout<<sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
