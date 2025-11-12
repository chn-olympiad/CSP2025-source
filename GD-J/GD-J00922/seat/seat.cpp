#include <bits/stdc++.h>
using namespace std;
const int N=110;
long long n,m,num[N*N],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(long long i=1;i<=(n*m);i++)
		cin>>num[i];
	x=num[1];
	sort(num+1,num+n*m+1);
	for(long long i=(n*m);i>=1;i--)
		if(x==num[i]){
			x=(n*m)-i+1;
			break;
		}
	if(x%n!=0){
		printf("%d ",(x/n+1));
		if((x/n+1)%2==0) printf("%d",n-(x%n)+1);
		else{
			if(x%n==0) cout<<n;
			else printf("%d",(x%n));
		}
	}
	else{
		printf("%d ",(x/n));
		if((x/n)%2==0){
			if(x%n==0) cout<<1;
			else printf("%d",n-(x%n)+1);
		}
		else{
			if(x%n==0) cout<<n;
			else printf("%d",(x%n));
		}
	}
}
