#include<bits/stdc++.h>
using namespace std;
int n;
const int mod=998244353;
int ans=0;
int a[5100];
void solve(){
	int qwq=1; 
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			sort(a+1,a+1+n);
			if(j-i>=2){
				next_permutation(a+i,a+j-1);
				int cnt=0;
				int maxx=-1;
				for(int k=i;k<=j;k++){
					for(int q=i;q<=j-1;q++){
						maxx=max(maxx,a[q]);
						cnt+=a[q];
					}					
				}
				for(int q=j;q<=n;q++){
					if(cnt+a[q]>2*max(maxx,a[q]))ans++;
					ans%=mod;
				}			
			}
			else break;	
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<3){
		puts("0");
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))puts("1");
		else puts("0");
		return 0;
	}
	sort(a+1,a+1+n);
	solve();
	printf("%d\n",ans);
	return 0;
}//RP++
