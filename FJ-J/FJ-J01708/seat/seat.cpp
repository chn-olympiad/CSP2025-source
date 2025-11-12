#include<bits/stdc++.h>
using namespace std;
struct node{
	int cj;
	int id;
}a[105];
bool cmp(node x,node y){
	return x.cj>y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum;
	cin>>n>>m;
	sum=m*n;
	for(int i=1;i<=sum;i++){
		cin>>a[i].cj;
		a[i].id=i;
	}
	sort(a+1,a+1+sum,cmp);
	int pmm;
	for(int i=1;i<=sum;i++){
		if(a[i].id==1){
			pmm=i;
			break;
		}
	}
	int X,Y;
	if(pmm%n){
		Y=pmm/n+1;
		if(Y%2)X=pmm%n;
		else X=n+1-(pmm%n);
	}
	else {
		Y=pmm/n;
		if(Y%2)X=n;
		else X=1;
	}
	cout<<Y<<" "<<X<<"\n";
	
	return 0;
} 
