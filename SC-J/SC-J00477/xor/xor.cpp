#include<bits/stdc++.h>
using namespace std;
long int a[500005];
long int b[500005];
struct ins{
	long int x;
	long int y;
};
ins c[500005];
bool sun(ins a,ins b){
	if(a.y==b.y)
		return a.x<b.x;
	return a.y<b.y;
}
bool sun2(ins a,ins b){
	if(a.y==b.y)
		return a.x<b.x;
	if(a.x==b.x)
		return a.y<b.y;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long int n=0,k=0;
	cin>>n>>k;
	b[0]=0;
	for(long int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	long int ci=0;
	for(long int i=1;i<=n;i++){
		for(long int j=i;j<=n;j++){
			if((b[j]^b[j-i])==k){
				ci++;
				c[ci].y=j;
				c[ci].x=j-i;
			}
		}
	}
	long int ji=0;
	sort(c+1,c+ci+1,sun);
	long int zi=0;
	for(long int i=1;i<=ci;i++){
		if(c[i].x>=zi){
			zi=c[i].y;
			ji++;
		}
	}
	long int jis=ji;
	ji=0;
	sort(c+1,c+ci+1,sun2);
	zi=0;
	for(long int i=1;i<=ci;i++){
		if(c[i].x>=zi){
			zi=c[i].y;
			ji++;
		}
	}
	cout<<max(ji,jis);
	return 0;
}