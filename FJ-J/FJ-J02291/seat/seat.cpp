#include<bits/stdc++.h>
using namespace std;
int n,m,z[15][15],k=1,f=0;
struct node{
	int id,f;
}a[200];
bool cmp(node a,node b){
	return a.f>b.f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].f;
		a[i].id=i;
	}
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[k].id==1){
					cout<<i<<" "<<j;
					f=1;
					break;
				}
				k++;
			}
		}
		else if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[k].id==1){
					cout<<i<<" "<<j;
					f=1;
					break;
				}
				k++;
			}
		}
		if(f==1){
			break;
		}
	}
	return 0;
}
