#include<bits/stdc++.h>
using namespace std;
int a[100000000],ans,k,n,xmg;
int maxn=0;
int anss=0;
bool cmp(int x,int y){
	return x>y;
}
void polygon(int x){
	xmg++;
	if(x>n){
		return;
	}
	for(int i=x+1;i<=n;i++){
		anss+=a[i];
		maxn=max(maxn,a[i]);
		if(anss>(maxn*2)&&xmg>=3){
			ans++;
			polygon(i+1);
		}
		else{
			polygon(i+1);
		}
	}
	return;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		xmg=1;
		maxn=0;
		polygon(i);
	} 
	cout<<ans;
	return 0;
}
