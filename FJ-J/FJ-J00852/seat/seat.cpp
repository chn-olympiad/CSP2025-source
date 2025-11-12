#include<iostream>
#include<algorithm>
#include<cstdio>
struct node{
	int c;
	int num;
}a[200];
int x(node a,node b){
	return a.c>b.c;
}
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,ans,u,v[11][11]={};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].c;
		a[i].num=i;
		if(i==1){
			ans=a[i].c;
			u=a[i].num;
		}
	}
	int cnt=1;
	sort(a+1,a+n*m+1,x);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2!=0){
				v[j][i]=a[cnt].num;
				cnt++;
				if(v[j][i]==u){
					cout<<i<<" "<<j;
					break;
				}
			}
			if(i%2==0){
				v[m-j+1][i]=a[cnt].num;
				cnt++;
				if(v[m-j+1][i]==u){
					cout<<i<<" "<<m-j+1;
					break;
				}
			}
		}
	}
	return 0;
}
