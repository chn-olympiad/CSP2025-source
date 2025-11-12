#include<bits/stdc++.h>
using namespace std;
int m,n,a,fro,bac,a0,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
		cin>>m>>n>>a;
		while(cin>>a0){
			if(a0>a)fro++;
			else bac++;
		}
		c=fro/n+1;
		r=(fro+1)%(n);
		if(c%2==0)r=n+1-r;
		cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
