#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int data;
	bool b=0;
}a[120];
struct Seat_ans{
	int i,j;
}ans;
int id[20][20];
bool f(node x,node y){
	return x.data>y.data;
}
void ID(){
	int I=1,J=1,it=1;
	while(it<=(n*m)&&I<=n&&J<=m){
		if(((it-1)/n)%2==0) {
		for(int i=1;i<n;i++){
			id[I][J]=it;
			I++,it++;
		}
	    }else{
		for(int i=1;i<n;i++){
			id[I][J]=it;
			I--,it++;
		}
	}
	    id[I][J]=it;
		J++,it++;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a[i].data;
		if(i==1)a[i].b=1;
	}
	sort(a+1,a+n*m+1,f);
	ID();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(a[id[i][j]].b==1){
			ans.i=i,ans.j=j;
		}
	}
	cout<<ans.j<<" "<<ans.i;
	return 0;
} 
