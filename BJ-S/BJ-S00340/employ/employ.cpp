#include<bits/stdc++.h>
using namespace std;
string stra;
int n,c[505],a[505],m,sum;
long long mod=998244353,num=1;
bool bok;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>stra;
	for(int i=0;i<stra.size();i++){
		if(stra[i]==0){
			bok=1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0)sum++;
	}
	if(!bok){
		for(int i=2;i<=n;i++){
			num=(num*i)%mod;
		}
		printf("%lld",num%mod);
		return 0;
	}
	for(int i=1;i<=n;i++){
		int aa=0;
		for(int j=0;j<stra.size();j++){
			if(stra[j]==0)aa++;
			if(aa>c[i]){
				for(int k=j;k>=0;k--){
					if(stra[k]==1){
						a[i]=k;
						break;
					}
				}
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
			num=(num*a[i]+mod)%mod;
		}
	
	printf("%lld",num%mod);
	return 0;
}
