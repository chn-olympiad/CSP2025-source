#include<bits/stdc++.h>
using namespace std;
long long i,n,m,f,v,a[10000],p=1,q=1,s=1;
long long cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)cin>>a[i];
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++){
		if(a[i]==f){
			v=i;
			break;
		}
	}
	if(v==s){
		cout<<1<<' '<<1;
		return 0;
	}
	while(s!=n*m){
		s++;
		if(q%2==1){
			if(p!=n)p++;
			else q++;
		}
		else{
			if(p!=1)p--;
			else q++;
		}
		if(s==v){
			cout<<q<<' '<<p;
			break;
		}
	}
}
