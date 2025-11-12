#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,cnt=0;
ll a[1000001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ll f=1;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			cnt++;
			f=i+1;
		}else{
			ll sum=a[i];
			for(int j=i-1;j>=f;j--){
				sum=sum^a[j];
				if(sum==k){
					cnt++;
					f=i+1;
					break;
				}
			}
		}
	}
	printf("%d",cnt);
	




	return 0;
	fclose(stdin);
	fclose(stdout);
}

