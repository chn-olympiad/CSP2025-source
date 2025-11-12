#include<bits/stdc++.h>
using namespace std;
struct s{
	int name;
	bool f;
}a[105];
int n,m;
int c,r;
s t[105],re;
void pao(){
	for(int i=1;i<=n*m;i++){
		for(int j=i;j>=1;j--){
			if(a[j].name>a[j-1].name){
				re.name=a[j].name;
				re.f=a[j].f;
				a[j].name=a[j-1].name;
				a[j].f=a[j-1].f;
				a[j-1].name=re.name;
				a[j-1].f=re.f;
			}else{
				break;
			}
		}
	}
	return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i=0;i<=104;i++) t[i].name=-1;
	cin>>n>>m;
	cin>>a[1].name;
	a[1].f=1;
	int N=n*m+1;
	for(int i=2;i<N;i++) cin>>a[i].name;
	pao();
	for(int i=0;i<n*m;i++){
		if(a[i].f){
			c=i/n+1;
			if(c%2)	r=i%n+1;
			else r=m-i%n;
			break;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
