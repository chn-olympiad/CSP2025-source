#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100005],d,c=1,l,x;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	l=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			d++;
		}
		if(a[i]==1){
			c++;
		}
	}
	if(k==0){
		if(d==1||d==0){
			cout<<d;
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]+a[i+1]==0){
					x++;
				}
				else{
					x=1;
					l=x;
				}
			}
		}
		cout<<c;
	}
	return 0;
}
