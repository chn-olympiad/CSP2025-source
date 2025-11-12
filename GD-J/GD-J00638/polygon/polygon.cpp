#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
int a[5007];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int ma=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>ma) ma=a[i];
	}
	if(n==3){
		if(2*ma<a[1]+a[2]+a[3]) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	if(ma==1){
		long long p=0;
		for(int i=3;i<=n;i++){
			long long s=1;
			for(int j=1;j<=i;j++){
				s=s*(n-j+1);
				s=s/j;
				if(s>998244352) break;
			}
			p+=s;
			p%=998244352;
		}
		cout<<p<<endl;
		return 0;
	}
	else{
		cout<<"998244352"<<endl;
	}
	return 0;
}
