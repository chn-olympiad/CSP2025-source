#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],s[500005],las,ans;
bool flagst=1,flagnd=1,flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=s[i-1]^a[i];
		if(a[i]!=0&&flagst) flagst=0;
		if(a[i]!=0&&a[i]!=1&&flagnd) flagnd=0;
	}
	if(flagst) printf("%lld",n/2);
	else if(flagnd){
		ll ling=0,yi=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) yi++;
			else if(a[i]==0) ling++;
		}
		if(k==0) printf("%lld",yi/2+ling);
		else if(k==1) printf("%lld",yi);
	}
	else{
		for(int i=1;i<=n;i++){
			flag=0;
			for(int j=i;j>=las;j--){
				if((s[i]^s[j-1])==k){
					flag=1;
					break;
				}
			}
			if(flag){
				ans++;
				las=i+1;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}