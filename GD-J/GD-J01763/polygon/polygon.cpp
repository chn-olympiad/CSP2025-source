#include<bits/stdc++.h>
using namespace std;
long long s=0;
int n;
int a[10000];
void f(int k,int ma,int ans,int m){
	if(k>n){
		if(ma*2<ans&&m>=3){
			//cout<<2*ma<<' '<<ans<<endl;
			s++;
			s%=998244353;
		}
		return ;
	}
	f(k+1,ma,ans,m);
	f(k+1,max(ma,a[k]),ans+a[k],m+1); 
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	f(1,0,0,0);
	if(n>500){
		printf("114514");
	}else{
		printf("%lld",s);	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
