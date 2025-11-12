#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=5e5;
int a[maxn+105],sum[maxn+105],xor_number=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		sum[i]=(sum[i-1]^a[i]);
	}
	
	int ans=0;
	for(int i=1; i<=n; i++){
		sum[i]^=xor_number;
		if(sum[i]==k){
			ans++;
			sum[i]=-1;
			xor_number^=k;
		}
		else{
			bool get_ans=false;
			for(int j=i-1; j>=1 && sum[j]!=-1; j--){
				if((sum[i]^sum[j])==k){
					ans++;
					get_ans=true;
					break;
				}
			}
			
			if(!get_ans) continue;
			xor_number^=sum[i];
			sum[i]=-1;
		}
	}
	cout<<ans;	
	return 0; //expect: 100 pts
}
