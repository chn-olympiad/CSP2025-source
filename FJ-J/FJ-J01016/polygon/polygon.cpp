#include<iostream>
using namespace std;

long long n,a[5005],now[5005],u,t,c;
int o(long long he,long long maxn,int p){
	if(he>maxn*2){
		u=(u+1)%998244353;
	}
	for(int i=p+1;i<n;i++){
		if(now[i]==0){
			now[i]=1;
			t=maxn;
			if(a[i]>maxn){
				maxn=a[i];
			}
			o(he+a[i],maxn,i);
			maxn=t;
			now[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	o(0,0,-1);
	cout<<u;
	return 0;
}
