#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void read(T&x){
	int f=1;x=0;char c;
	do{c=getchar();if(c=='-')f=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));x=x*f;
}
int n,m,a[200],p;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int o=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==o){
			p=i;
			break;
		}
	}int k=p/n,kk=p%n;
	if(kk==0)k--;
	if((k+1)%2==1){
		cout<<(k+1)<<" "<<(kk==0?n:kk);
	}
	else{
		cout<<(k+1)<<" "<<(kk==0?1:(n-kk+1));
	}
	return 0;
}
