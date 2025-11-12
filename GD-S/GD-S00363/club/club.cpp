#include<bits/stdc++.h>
using namespace std;
long t,n,c1,c2,c3,feel;
struct st {
	long f1,f2,f3;
} c[900010];
void cj(long k,long x,long y,long z,long sum){
	if(x>n/2||y>n/2||z>n/2){
		return;
	}
	if(k>n){
		feel=max(sum,feel);
		return;
	}
	cj(k+1,x+1,y,z,sum+c[k].f1);
	cj(k+1,x,y+1,z,sum+c[k].f2);
	cj(k+1,x,y,z+1,sum+c[k].f3);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long l=1; l<=t; l++) {
		cin>>n;
		for(long i=1; i<=n; i++) {
			cin>>c[i].f1>>c[i].f2>>c[i].f3;
		}
		cj(1,0,0,0,0);
		cout<<feel<<"\n";
		feel=0;
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
