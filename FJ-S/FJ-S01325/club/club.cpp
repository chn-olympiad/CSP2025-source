#include<bits/stdc++.h>
using namespace std;
int t,n,xx,j1j,j2j,j3j;
struct ll{
	int a,b,c;
}a[100001];
void dg(int x,int i){
	if(j3j>n/2){
		return;
	}
	if(j2j>n/2){
		return;
	}
	if(j1j>n/2){
		return;
	}
	xx=max(xx,x);
	if(i==n)return;
	j1j++;
	dg(x+a[i+1].a,i+1);
	j1j--;
	j2j++;
	dg(x+a[i+1].b,i+1);
	j2j--;
	j3j++;
	dg(x+a[i+1].c,i+1);
	j3j--;
	return;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	for(int tx=1;tx<=t;tx++){
		xx=0;
		j1j=0;
		j2j=0;
		j3j=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		}
		dg(0,0);
		printf("%d\n",xx);
	}
	return 0;
}
