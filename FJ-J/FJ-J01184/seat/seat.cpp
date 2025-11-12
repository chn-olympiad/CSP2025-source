#include<bits/stdc++.h>
using namespace std;
long long n,m,r[110][110],s,k=1,p;
struct node{
	long long bh,cj;
};
node a[110];
bool cmp(node x,node y){
	return x.cj>y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long s=m*n;
	for(int i=1;i<=s;i++){
		cin>>a[i].cj;
		a[i].bh=i;
	}
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=s;i++){
		if(a[i].bh==1) {
			p=i;
		}
	}
	long long i;
	if(p<=n) cout<<1<<' '<<p<<endl;
	else{
		s=p/n;
		if(s*n!=p) s+=1;
		k=s*n;
		i=p%n;
		if(s%2==0){
			cout<<s<<' '<<i+1<<endl;
		}
		else if(s%2!=0){
			cout<<s<<' '<<i<<endl;
		}
	}
	return 0;
}