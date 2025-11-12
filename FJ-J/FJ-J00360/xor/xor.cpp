#include<bits/stdc++.h>
using namespace std;
int a,b,n,k[500005];
long long c[500005],d[500005],m,mmax,zs;
int main(){
	freopen("xor4.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	d[0]=0;
	for(int i=1;i<=a;i++){
		cin>>c[i];
		if(c[i]!=1) n=1;
		d[i]=d[i-1]^c[i];
	}
	if(n==0){
		cout<<a/2<<endl;
	}
	else{

			zs=0;
			for(int i=1;i<=a;i++){
			for(int j=i;j<=a&&j>=i;j++){
				m=d[j]^d[i-1];
				if(i==j&&b==c[i]){
					zs++;
					i++;
					j++;
				}
				else if(m==b){
					zs++;
					i=j;
				}
			}
		
		}
		
		cout<<zs<<endl;
	}
return 0;
}
