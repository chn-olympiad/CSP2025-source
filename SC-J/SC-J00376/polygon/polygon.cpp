#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int c[N];
int f[N];
long long sum1=0;
int main (){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int a,maxn=-1;
	cin>>a;
	if(a<3){
		cout<<0;
	}else{
		for(int i=1;i<=a;i++){
			cin>>c[i];
			maxn=max(maxn,c[i]);
		}
		if(a=3){
			if(2*maxn<c[1]+c[2]+c[3])
			cout<<1;
			else cout<<0;
		}
		else if(maxn==1){
			for(int i=3;i<=a;i++){
				long long sum2=1,sum3=1;
				for(int j=i+1;j<=a;j++){
			sum2*=i%998244353;
		}
		for(int i=2;i<=i;i++){
		sum3*=i%998244353;
		}
		sum1=sum2/sum3%998244353;
			}
			cout<<sum1;
		}
}
	return 0;
}