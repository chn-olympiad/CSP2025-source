#include<bits/stdc++.h>
using namespace std;
struct node{
	int aa;
	bool as[10];
}a[500005];
int n,m,ans;
bool f(int l,int r){
	bool y[10]={},kl=1;
	for(int i=l;i<r;i++){
		for(int j=1;j<=10;j++){
			if(a[i].as[j]==a[i+1].as[j])y[j]=0;
			else y[j]=1;
		}
		for(int j=1;j<=10;j++){
			if(y[j]!=a[i].as[j]){
				kl=1;
				break;
			}
		}
		if(!kl)return 1;
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	a[n+1].aa=m;
	for(int i=1;i<=n;i++)cin>>a[i].aa;
	for(int i=1;i<=n+1;i++){
		int o,d=1;
		o=a[i].aa;
		while(o){
			a[i].as[d++]=o%2;
			o/=2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f(i,j)){
				ans++;
				i=j+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
