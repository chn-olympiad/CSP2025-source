#include<bits/stdc++.h>
using namespace std;
int n,m,ex=1,ey=1;
struct node{
	int s,t;
}a[100005];
bool cmp(node x,node y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].t=i;
	}
	int f=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[f].t==1){
				break;
			}
			if(j!=1){
				if(i%2==0) ey--;
				else ey++;
				f++;
			}
			
		}
		if(a[f].t==1) break;
		ex++;
		f++;
	}
	freopen("seat.out","w",stdout);
	cout<<ex<<" "<<ey;		
	
	return 0;	
}
