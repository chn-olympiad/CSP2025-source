#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;//记得开大点 
long long t,n,arr1[N],arr2[N],arr3[N]; 
long long cnt1,cnt2,cnt3,maxv1,maxv2,maxv3;
long long ans=0;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++){
			scanf("%lld%lld%lld",&arr1[i],&arr2[i],&arr3[i]);
		}
		for(long long i=1;i<=n;i++){
			if(n==2){
				if(arr2[i]==0&&arr3[i]==0){
					ans+=arr1[i];
					cnt1++;
					if(cnt1>1){
						sort(arr1+1,arr1+1+n,cmp);
						ans=arr1[1];
					}
				}
				if(arr1[i]==0&&arr3[i]==0){
					ans+=arr2[i];
					cnt2++;
					if(cnt2>1){
						sort(arr2+1,arr2+1+n,cmp);
						ans=arr2[1];
					}
				}
				if(arr1[i]==0&&arr2[i]==0){
					ans+=arr3[i];
					cnt3++;
					if(cnt3>1){
						sort(arr3+1,arr3+1+n,cmp);
						ans=arr3[1];
					}
				}
			}
			int a=max(arr1[i],max(arr2[i],arr3[i]));
			if(arr1[i]==a){
				maxv1+=arr1[i];
				cnt1++;
			}else if(arr2[i]==a){
				maxv2+=arr2[i];
				cnt2++;
			}else if(arr3[i]==a){
				maxv3+=arr3[i];
				cnt3++;
			}
			if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
				ans=maxv1+maxv2+maxv3;
			}
		}
		printf("%lld\n",ans);
		memset(arr1,0,sizeof arr1);
		memset(arr2,0,sizeof arr2);
		memset(arr3,0,sizeof arr3);
		maxv1=0;maxv2=0;maxv3=0;cnt1=0;cnt2=0;cnt3=0;ans=0;
	}
	return 0;
} 
