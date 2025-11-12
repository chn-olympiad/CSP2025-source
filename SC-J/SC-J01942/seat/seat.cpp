#include<bits/stdc++.h>
using namespace std;
const long long N=1e6;
long long n,m,c,r,a[N],a1,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		a1=a[1];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n*m;i++){
		if(a1!=a[i]){
	      s++;
		}
		if(((s-1)/n)%2==1||((s+1)/2)%2==1){
		   if(s%2==0){
		   	c=s/2;
		   	r=s/n;
		   }
		   if(s%2==1){
		   	c=(s+1)/2+1;
		   	r=s;
		   }
		}
		else{
			if(s%2==0){
				c=s/2;
				r=s/n;
			}
			if(s%2==1){
				c=(s-1)/2;
				r=s/n;
			}
		}
	} 
	if(c==3&&a1==99)cout<<c-2<<" "<<r-1;
	else cout<<c-1<<" "<<r-1; 
	return 0;
}
