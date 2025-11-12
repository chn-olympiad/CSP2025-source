#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int v,id;
}a[15];
bool cmp(node a,node b){
	return a.v>b.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].id=i;
	}
	sort(a+1,a+(n*m)+1,cmp);
	int i=1,j=1;
	bool f=1;
	for(int k=1;k<=n*m;k++){
		if(a[k].id==1){
			cout<<j<<' '<<i;
			return 0;
		}
		if(f==1){
			i++;
			if(i>n){
				f=0;
				i=n;
				j++;
			}
		}
		else{
			i--;
			if(i<1){
				f=1;
				i=1;
				j++;
			}
		}
	}
}
