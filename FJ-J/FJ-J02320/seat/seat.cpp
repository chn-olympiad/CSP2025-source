#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,s;
};
node a[105];
bool cmp(node x,node y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1) cnt=i;
	}
	int x,y;
	x=((cnt-1)/n)+1;
	if(x%2==1) y=((cnt-1)%n)+1;
	else y=n-((cnt-1)%n);
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

