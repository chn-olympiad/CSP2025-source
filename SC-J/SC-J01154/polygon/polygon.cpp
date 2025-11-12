#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
int a[5005],k=3,n,b[5005];
long long ans,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	sort(b+1,b+1+n);
	while(k<=n){
		for(int i=k;i>=1;i--){
			if(a[i]>n-k+i){
				if(i==1){
					k++;
					if(k>n){
						cout<<ans%N;
						return 0;
					}
				}else{
					a[i-1]++;
					a[i]=a[i-1]+1;
				}
				for(int j=i;j<=k;j++){
					if(j==1){
						a[j]=1;
					}
					a[j]=a[j-1]+1;
				}
				ans%=N;
			}
		}
		for(int i=1;i<k;i++){
			cnt+=b[a[i]];
		}
		if(cnt>b[a[k]]){
			ans++;
		}
		a[k]++;
		cnt=0;
	}
	return 0;
} 