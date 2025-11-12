#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int score;
	int num,de;	
}a[105];
bool cmp1(node a,node b){
	return a.score>b.score;
}
bool cmp2(node a,node b){
	return a.num<b.num;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp1);
	for(int i=1;i<=n*m;i++){
		a[i].de=i;
	}
	sort(a+1,a+n*m+1,cmp2);
	int c=(a[1].de-a[1].de%n)/n+1,r;
	if(c%2==1){
		r=(a[1].de-1)%n+1;
	}else{
		r=n-a[1].de%n+1;
	}
	cout<<c<<' '<<r;
	
	return 0;
}
