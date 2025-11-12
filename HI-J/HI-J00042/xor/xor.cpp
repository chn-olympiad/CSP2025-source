#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N];
int cnt0,cnt1,cnt;
int main(){
				freopen("xor.in","r",stdin);
				freopen("xor.out","w",stdout);
				cin>>n>>k;
				for(int i=1;i<=n;i++){
								cin>>a[i];
								if(a[i]==0) cnt0++;
								else if(a[i]==1) cnt1++;
								else cnt++;
				}
				if(k==0&&cnt1==n){
								cout<<n/2;
								return 0;
				}
				if(k<=1&&cnt1+cnt0==n){
								if(k==0){
												int sum1=0,ans=0;
												for(int i=1;i<=n;i++){
																if(a[i]==1) sum1++;
																if(sum1%2==0){
																				ans++;
																				sum1=0;
																}
												}
												cout<<ans;
												return 0;
								}
								else{
												int sum1=0,ans=0;
												for(int i=1;i<=n;i++){
																if(a[i]==1) sum1++;
																if(sum1%2==1){
																				ans++;
																				sum1=0;
																}
												}
												cout<<ans;
												return 0;
								}
				}
				return 0;
}
