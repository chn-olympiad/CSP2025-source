#include<bits/stdc++.h>
using namespace std;

int b[100001],sum;
struct node{
	int csf,css,pri;
}a[10001];

int cmp(node a,node b){
	return a.pri<b.pri;
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	int m,n,k;
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].csf>>a[i].css>>a[i].pri;
	}
	int l=m-1;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=l;i++)	sum=sum+a[i].pri;
	cout<<sum;
	return 0;
}
