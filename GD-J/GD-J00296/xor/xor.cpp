#include<bits/stdc++.h>
using namespace std;
long long n,m,a[114514],ans,t,l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long q=0;q<n;q++){
		t=0,l=0;
		for(long long i=q;i<n;i++){
			t^=a[i];
			if(t==m){
				l++;
				t=0;
			}
		}
		ans=max(ans,l);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
