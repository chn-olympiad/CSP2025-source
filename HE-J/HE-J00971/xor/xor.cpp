#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long k,a[N],ans=0,m;
bool b[N]={0};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		for(int j=1;j<=i;j++){
			m=a[j];
			for(int l=j+1;l<=i;l++){
				m=m^a[l];
			}
	    	if(m==k){
	    		bool f=0;
	    		for(int s=j;s<=i&&f==0;s++){
	    			if(b[s]==1){
	    				f=1;
					}
				}
				if(f==0){
					ans++;
					for(int s=j;s<=i;s++){
						b[s]=1;
					}
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
