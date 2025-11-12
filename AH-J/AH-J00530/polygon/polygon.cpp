#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5005],ans,num,p;	
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<1<<n;i++){
		int cnt=i,k=0;
		num=0,p=0;
		for(int j=1;j<=n;j++){
			if(cnt%2==0){
				k++;
				num+=a[j];
				p=max(p,a[j]);}
			cnt/=2;
		}
		if(k>=3&&num>p*2) ans++;
		ans%=N;
	}
	cout<<ans%N;
    return 0;
}
