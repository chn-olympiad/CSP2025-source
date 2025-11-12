#include<bits/stdc++.h>
using namespace std;
int n,m,num=0,c,r;
int a[110]={};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])num++;
	}
	sort(a+1,a+n*m+1,cmp);
	c=(num/n)+1;
	if(c%2)r=(num+1)-(c-1)*n;
	else r=n-((num+1)-(c-1)*n)+1;
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
