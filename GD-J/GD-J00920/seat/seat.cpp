#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long x=a[1],p=1;
	sort(a+1,a+n*m+1,cmp);
	long long i=0;
	while(1){
		if(a[++i]==x){
			p=i;
			break;
		}
	}
	if((p%n==0?p/n:p/n+1)%2==1){
		cout<<(p%n==0?p/n:p/n+1)<<' '<<(p%n==0?n:p%n);
	}
	else{
		cout<<(p%n==0?p/n:p/n+1)<<' '<<(p%n==0?1:m-p%n+1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
