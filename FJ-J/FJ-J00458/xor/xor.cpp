#include <bits/stdc++.h>
using namespace std;
struct str{
	int b,e;
}u[1000010];
int n,k,a[500010],sum;
bool cmp(str p,str q){
	if(p.e!=q.e) return p.e<q.e;
	else return p.b<q.b;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int t=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=(a[i-1]^x);
	}
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[i]^a[j])==k){
				u[++t].b=i+1,u[t].e=j;
			}
		}
	}
	sort(u+1,u+t+1,cmp);
	int r=0;
	for(int i=1;i<=t;i++){
		if(u[i].b>r){
			sum++;
			r=u[i].e;
		}
	}
	cout<<sum;
	return 0;
}

