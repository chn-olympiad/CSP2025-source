#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,id;
}a[1000];
bool cmp(node a,node b){
	return a.v>b.v;
}
int n,m,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].v,a[i].id=i;
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				cnt++;
				if(a[cnt].id==1){
					cout<<i<<' '<<j;
					return 0;
				}
			} 
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(a[cnt].id==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
