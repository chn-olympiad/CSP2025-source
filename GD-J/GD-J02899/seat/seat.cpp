#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
int n,m,cj,a[173],pm=1,n1=0,m1=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m*n;i++){
    	scanf("%d",&a[i]);
    	if(i==1)cj=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=m*n;i;i--){
		if(a[i]==cj)break;
		pm++;
	}
	n1=(pm-1)/n+1;
	if(n1%2==1){
		m1=pm-(n1-1)*m;
	}
	else{
		m1=m-(pm-(n1-1)*m)+1;
	}
	cout<<n1<<" "<<m1;
    fclose(stdin);
    fclose(stdout);
	return 0;
}

