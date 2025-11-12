#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long n,k,x,sum;
long long ar[N],br[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&ar[i]);
	}
	for(int i=1;i<=n;i++){
		if(br[i]==0){
			x=ar[i];
		}
		else{
			break;
		}
		if(x==k){
			sum++;
			br[i]=1;
//			cout<<i<<" "<<i<<endl;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			if(br[j]==0){
				x=x^ar[j];
			}
			else{
				continue;
			}
			if(x==k){
				sum++;
				for(int l=i;l<=j;l++){
					br[l]=1;
				}
//				cout<<i<<" "<<j<<endl;
			}		
		}
	}
	printf("%lld",sum);
	


	return 0;
}

