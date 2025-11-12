#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
struct op{
	int s;
	int id;
}a[N];
bool cmp(op x,op y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int num=0;
	for(int i=1;i<=m;++i){
		if(i%2==1){
			for(int j=1;j<=n;++j){
				num++;
				if(a[num].id==1){
					cout<<i<<' '<<j;
					break;
				}
			}
		}
		else{
			for(int j=n;j>=1;--j){
				num++;
				if(a[num].id==1){
					cout<<i<<' '<<j;
					break;
				}
			}
		}
	}
	return 0;
}
