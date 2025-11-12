#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
	int id,x;
}a[100010];
bool cmp(Node a,Node b){
	return a.x>b.x;
}
int s[110][110];
int main(){
//	freopen("seat2.in","r",stdin);
//	freopen("seat2.out","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].x,a[i].id=i;
	sort(a+1,a+1+n*m,cmp);
	int it=0;
	int an=0,am=0;
//	for(int i=1;i<=n*m;i++) cout<<a[i].x<<' ';
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				s[j][i]=a[++it].x;
				if(a[it].id==1) an=i,am=j;
			}	
		}else{
			for(int j=n;j>=1;j--){
				s[j][i]=a[++it].x;
				if(a[it].id==1) an=i,am=j;
			}
		}
	}
	cout<<an<<' '<<am;
	return 0;
}
/*
2 2
99 100 97 98
*/ 
