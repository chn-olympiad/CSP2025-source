#include<bits/stdc++.h>
using namespace std;
long long a[100001];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long ans=a[1],x=0,y=1,awa=1;
	sort(a+1,a+(n*m)+1,cmp);
	for(long long i=1;i<=n*m;i++){
		if(awa==1){
		if(x+1<=n)x++;
		else{
			awa=0;
			y++;
		}
		}else{
			if(x-1>=1){
				x--;
			}else{
			awa=1;
			y++;	
			}
		}	
		if(a[i]==ans){
			cout<<y<<" "<<x;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
