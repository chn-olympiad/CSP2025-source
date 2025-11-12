#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,x,y,tot=1;
struct node{
	int mark,num;
}a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	while(cin>>a[tot].mark){
		a[tot].num=tot;
		tot++;
	}
	tot-=1;
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=tot;j++){
			if(i==j) continue;
			if(a[i].mark>a[j].mark and a[j].num<a[i].num){
				swap(a[i].num,a[j].num);
			}
		}
	}
	x=a[1].num/n+1;
	if(a[1].num%n==0) x-=1;
	if(x%2!=0){
		y=a[1].num%n;
		if(y==0) y=n;
	}else{
		int u=a[1].num%n;
		y=n-u+1;
	}
	cout<<x<<" "<<y;
}
