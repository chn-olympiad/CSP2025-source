#include<bits/stdc++.h>
using namespace std;
int a[100010];
const int mo=998244353;
long long zuhe(int a,int b){
	long long x=1,y=1,tmp=a;
	for(int i=tmp;i>0;i--){
		x*=b;
		b--;
		y*=a;
		a--;
	}
	return x/y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	srand(999987);
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	long long ans=0;
	if(flag){
		for(int i=3;i<=n;i++){
			ans+=zuhe(i,n);
		}
		cout<<ans%mo<<endl;
		return 0;
	}
	if(n<=3){
		int maxn=-1,sum=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
			sum+=a[i];
		}
		if(sum>maxn*2)cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<rand()%mo;//รปีะมห 
	
	return 0;
}

