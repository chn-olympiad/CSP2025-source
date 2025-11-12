#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],b[500010],ans;
bool flag;
vector<long long> vis;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	bool flag=1;
	b[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=b[i-1]^a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	if(k==0&&flag==1){
		cout<<n/2;
	}
	else if(k<=1){
		long long cnt1=0,cnt2=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt1++;
				}
				else if(i!=n&&a[i]==1&&a[i+1]==1){
					cnt1++;
					i++;
				}
			}
			cout<<cnt1;
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt2++;
				}
			}
			cout<<cnt2;
			return 0;
		}
	}
	else{
		for(int len=1;len<=n;len++){
			for(int l=1,r=len;r<=n;l++,r++){
				if((b[r]^b[l-1])==k){
					flag=1;
					for(long long x:vis){
						if(l<=x&&x<=r){
							flag=0;
							break;
						}
					}
					if(flag==1){
						ans++;
						vis.push_back(l);
						vis.push_back(r);
					}
					
				}
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
