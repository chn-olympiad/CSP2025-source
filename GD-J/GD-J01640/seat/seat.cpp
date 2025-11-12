#include<bits/stdc++.h>
using namespace std;
int a[105],x;
bool cmp(int b,int c){
	return b>c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			cout<<ceil(i*1.0/n)<<" ";
			if(int(ceil(i*1.0/n))%2==1){
				if(i%n==0)cout<<n;
				else{
					cout<<i%n;
				}
			}
			else{
				if(i%n==0)cout<<1;
				else{
					cout<<n-(i%n)+1;
				}
			}
			break;
		}
	}
	return 0;
}
