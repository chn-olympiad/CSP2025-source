#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int a[110];
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int r=a[1];
	int nm=n*m;
	sort(a+1,a+nm+1,cmp);
	int js=1;
	for(;js<=n*m;js++){
		if(a[js]==r)break;
	}
	int ansn,ansm;
	if(js%n!=0)ansn=js/n+1;
	else if(js%n==0)ansn=js/n;
	if(ansn%2==0)ansm=n-(js%n)+1;
	else if(ansn%2!=0)ansm=js%n;
	printf("%d %d",ansn,ansm); 
	return 0;
	
}
