#include <bits/stdc++.h>
using namespace std;
const int MAXN=5005;
const long long MOD=998244353;
long long a[MAXN];
long long n;

void zda(){
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans%MOD)*2;
	}
	long long cnt1=0,cnt2=0;
	cnt1=n*1;
	cnt2=n*(n-1)/2;
	//cout<<cnt2<<endl;
	ans=(ans-1-cnt1-cnt2+MOD)%MOD;
	cout<<ans<<endl;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long ansm=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>ansm){
			ansm=a[i];
		}
	}
	if(n<3){   //test 1---3
		cout<<'0'<<endl;
		return 0;
	}
	if(n==3){   //test 1---3
		if(a[1]+a[2]+a[3]>2*ansm){
			cout<<'1'<<endl;
			return 0;
		}else{
			cout<<'0'<<endl;
			return 0;
		}
	}
	if(ansm==1){  //zhen dui a wei 1 test 15---20
		zda();
	}
	//if(n<=10 && n>3){   //test 4---6
		
	//}
	return 0;
}
