#include<bits/stdc++.h>
#define ll long long
#define m(a) memset(a,0,sizeof(a))
using namespace std;
const int maxn=1e5+2;
int n,t,x,y,z,high,d,e,f,a[maxn],b[maxn],c[maxn];
ll num;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;++k){
		cin>>n;
		num=0,d=0,e=0,f=0,high=0;
		m(a),m(b),m(c);
		for(int i=1;i<=n;++i){
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				high=x;
				d++;
				a[d]=min(high-y,high-z);
			}
			else if(y>=x&&y>=z){
				high=y;
				e++;
				b[e]=min(high-x,high-z);
			}
			else {
				high=z;
				f++;
				c[f]=min(high-x,high-y);
			}
			num+=high;
		}
		if(d>n/2) {
			sort(a+1,a+1+d);
			for(int j=1;j<=d-n/2;++j)
				num-=a[j];
		}
		else if(e>n/2) {
			sort(b+1,b+1+e);
			for(int j=1;j<=e-n/2;++j)
				num-=b[j];
		}
		else if(f>n/2) {
			sort(c+1,c+1+f);
			for(int j=1;j<=f-n/2;++j)
				num-=c[j];
		}
		cout<<num<<'\n';
	}
	return 0;
}
