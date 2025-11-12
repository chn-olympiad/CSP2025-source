#include <bits/stdc++.h>
using namespace std;
long long n,sum;
int a[500010],k;
int main(){
	//k=1 0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    scanf("%lld %d",&n,&k);
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(k==0){
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				sum++;
			}
		}
	}else{
//		int flag=1;
//		if(a[i]!=1){
//			flag=0;
//		}
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
