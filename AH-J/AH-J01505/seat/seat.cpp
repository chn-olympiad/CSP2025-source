#include<bits/stdc++.h>
using namespace std;
int n,m,s;
struct node{
	int id;
	int x;
}a[5000];
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
 freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  ios::sync_with_stdio(false);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	int d;
	sort(a+1,a+1+s,cmp);
	for(int i=1;i<=s;i++){
		if(a[i].id==1){
			d=i;
			break;
		}
	}
//	cout<<d<<" ";
	if(d/m==0){
		cout<<1<<" "<<d;
	}
	else{
		if(d%m==0){
			if(d/m%2!=0) cout<<d/m<<" "<<m;
			else cout<<d/m<<" "<<1;
		}
		else{
			if(d/m%2==1) cout<<d/m+1<<" "<<m-d%m+1;
			else cout<<d/m+1<<" "<<d%m;
		}
	}
	return 0;
}
