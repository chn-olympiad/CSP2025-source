#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101],x,f=1;
int cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			long long b=i%m,c=i/m;
			if((i/m)%2==0){
				cout<<c+1<<" "<<b;
			}else{
				cout<<c+1<<" "<<m-b+1;
			}
			return 0;
		}
	}
	return 0;
}

