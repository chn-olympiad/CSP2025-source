#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[110],x=1,y=1,s,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)
	scanf("%lld",&a[i]);
	s=a[1];
	sort(a+1,a+1+n*m,greater<ll>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			printf("%lld %lld",x,y);
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		if(i%n==0)t++,x++;
		else{
			if(t%2==0)y++;
			else y--;
		}
	}
}
