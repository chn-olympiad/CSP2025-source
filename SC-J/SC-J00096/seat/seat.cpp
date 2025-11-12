#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b,p,q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n >>m;
	for(int i=1;i<=n*m ;i++) 
	cin>>a[i];
	b=a[1];
	sort(a+1,a+m*n+1);
	for(int i=1;i<=n*m;i++){
		if(p/2*2==2){
		q--;
		}
	
		else{
		q++;
		}
		
		if(q==n+1) q=n,p++;
		if(i==0) q=1,p++;
		if(a[i]==b){
			cout<<p<<" "<<q<<endl;
		}
		
	}
	return 0;
}