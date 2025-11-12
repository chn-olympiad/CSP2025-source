#include<bits/stdc++.h>
using namespace std;
int n;
struct book{
	int a,b,c;
};
bool way(book op,book po){
	return op.a<po.a;
}
book f[5010];
int x,y,z;
int o,p,q;
int num,sum;
int jsq;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		for(int i=0;i<3;i++){
			cin>>f[i].a;
		}
		sort(f,f+3,way);
		cout<<(f[0].a+f[1].a>f[2].a ? 1:0);
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>f[i].a;
	}
	num=f[1].a;
	sort(f,f+n,way);
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			num+=f[i].a;
			if(num>f[j+2].a){
				jsq=(jsq+1)%998244353;
			}
		}
	}
	cout<<jsq;
	return 0;
}
