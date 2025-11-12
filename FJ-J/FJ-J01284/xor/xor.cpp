#include<bits/stdc++.h>
using namespace std;
long long xf[1005][1005];
long long s[500005];
long long n,k;
long long a[500005];
int i1[500005];
int jo[500005];
int cu=0;
int pd(int x,int y){
	for(int i=1;i<=cu;i++){
		if((x>=i1[i] and x<=jo[i])or(y<=jo[i] and y>=i1[i])or
		(i1[i]>=x and jo[i]<=y)or(jo[i]<=y and i1[i]>=x)){
			return 0;
		}	
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=a[i]^s[i-1];
	}
	if(n<=100){
		long long cnt=0;
		for(int i=1;i<=n;i++){
			xf[i][i]=a[i];
			for(int j=i+1;j<=n;j++){
				xf[i][j]=xf[i][j-1]^a[j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(xf[i][j]==k and pd(i,j)){
					cnt++;
					i1[++cu]=i;
					jo[++cu]=j;
				}
			}
		}
		//cout<<cnt<<"\n";
		printf("%lld\n",cnt);
	}
	else {
		long long js=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(s[j]^s[i-1]==k and pd(i,j)){
					js++;
				}
			}
		}
		printf("%lld\n",js);
	}
	return 0;
}
