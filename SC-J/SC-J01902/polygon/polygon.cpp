#include<bits/stdc++.h>
using namespace std;
long long n,a[5009],b[5009],q;
void pd(int s,int k,int d){
	if(k==s){long long ma=-1,zx=0;
		for(int i=1;i<=k;i++){
			ma=max(ma,b[i]);
			zx+=b[i];
		}
		if(zx>ma*2){
//			for(int i=1;i<=k;i++){
//				cout<<b[i]<<" ";
//			}cout<<zx<<"\n";
			q++;
		}return;
	}
	for(int i=d;i<=n;i++){
		b[k+1]=a[i];
		pd(s,k+1,i+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=3;i<=n;i++){
		pd(i,0,1);
	}
	q%=998;
	q%=244;
	cout<<q%353;
	return 0;
}