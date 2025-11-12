#include <bits/stdc++.h>
using namespace std;
int n;
int a[5111];
long long ent=0;
int jc(int n,int i){
    int a=1;
	for(int n,i;i>0&&n>0;n--,i--){
		a*=n;
	}return a ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;

	long long ent=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}if(n==3){
		int m=max(a[0],a[1]);
		m=max(a[2],m);
		int all=a[1]+a[2]+a[0];
		if(all>2*m){
			cout<<1;
		}else{
			cout<<0;
		}

		return 0;
	}else{
		for(int i=3;i<=n;i++){
		ent+=(jc(n,i)/jc(i,i));
		//cout<<jc(n,i)<<" "<<jc(i,i)<<" ";
		//cout<<ent<<" ";
		ent%=998244353;
		}
		cout<<ent;

	}
	return 0;
}
