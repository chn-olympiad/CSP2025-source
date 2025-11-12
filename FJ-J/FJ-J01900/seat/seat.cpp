#include<bits/stdc++.h>
using namespace std;
struct node{
	int x_1,y_1;
	int grade;
	int p;
};
node a[150];
int n,m,ans;
bool cmp(node x,node y){
	return x.grade>y.grade;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].grade;
	} 
	int me=a[1].grade;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		a[i].p=i;
		if(a[i].grade==me){
			me=i;
			break;
		}
	}
	int gs=0;
	if(me%n){
		gs=me/n+1;
	}else gs=me/n;
	if(gs==0){
		cout<<1<<" ";	 
	}
	else cout<<gs<<" ";
	if(gs%2==1){
		cout<<me-(gs-1)*n;
	}else{
		cout<<n-(me-(gs-1)*n)+1;
	}
	return 0;
}
