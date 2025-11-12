#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int a[N];
bool cmp(int x,int y){
	return x>y; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	int n,m,l;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	l=a[1];sort(a+1,a+1+n*m,cmp);
	int r=1,c=1,fx=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==l){
			printf("%d %d",c,r);
			return 0;
		}
		if(r+fx>n||r+fx<1)c++,fx*=-1;
		else r+=fx;
	}
	return 0;
}

