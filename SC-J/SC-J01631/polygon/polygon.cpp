#include<bits/stdc++.h>
#define int long long
#define bug cout<<"!!!!BUG!!!!<<endl;"
using namespace std;
const int N=5e5,mod=9982444353;
int n,a[N],ans;

bool get(int i){
	int cnt=0,num=i,sum=0,maxx=0,j=1;
	while(num>0){
		if(num%2==1){
			cnt++;
			sum+=a[j];
			maxx=a[j];
		}
		num/=2;
		j++;
	}
	if(cnt>=3){
		if(sum-(2*maxx)>0){
			return 1;
		}
	}
	return 0;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<(1<<n);i++){
		if(get(i)){
			ans++;
			ans%=mod;
		}
	}
	
	cout<<(ans+mod)%mod;

	return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10
*/