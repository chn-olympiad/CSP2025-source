#include<bits/stdc++.h>
using namespace std;
const int N = 505,M=998244353;
long int n,m,b[N],c[N],cnt;
char a[N];
bool f(long int b[]){
	long int ans=0;
	for(int i=1;i<=n;i++){
		if(b[i]>c[i]&&a[i]!='0') ans++;
	}
	return ans>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%ld%ld",&n,&m);
	for(long int i=1;i<=n;i++){
		scanf("%c",&a[i]);
		c[i] += c[i-1];
		if(a[i]=='0') c[i]++;
	}
	for(long int i=1;i<=n;i++){
		scanf("%ld",&b[i]);
	}
	if(m==1&&c[n]==0){
		cnt = 1;
		for(int i=n;i>=1;i--){
			cnt *= i;
			cnt %= M;
		}
		printf("%ld",cnt);
		return 0;
	}
	cnt += f(b)%M;
	for(long int i=1;i<=n;i++){
		for(long int j=1;j<=n;j++){
			if(a[i]==a[j]) continue;
			swap(a[i],a[j]);
			cnt += f(b)%M;
		}
	}
	printf("%ld",cnt/2); 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
