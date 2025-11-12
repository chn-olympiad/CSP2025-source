#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
struct node{
	int cj,num;
}a[N];
bool cmp(const node&x,const node&y){
	return x.cj>y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cj;
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	bool flag=false;
	for(int j=1;j<=m;j++){
		if(flag) break;
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(a[++cnt].num==1){
					cout<<j<<" "<<i;
					flag=true;
					break;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				if(a[++cnt].num==1){
					cout<<j<<" "<<i;
					flag=true;
					break;
				}
			}
		}
	}
	return 0;
}