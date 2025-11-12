#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,ans;
int a[N];
bool all1(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1) return false;
	}
	return true;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==2){
		if(a[1]==k&&a[2]==k) printf("2");
		else if(a[1]==k^a[2]==k) printf("1");
		else if((a[1]^a[2])==k) printf("1");
		else printf("0");
		return 0;
	}
	if(all1()&&k==0){
		printf("%d",n/2);
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			else if(i!=n){
				if(a[i]==a[i+1]){
					ans++;
					i++;
				}
			}
		}
	}else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
