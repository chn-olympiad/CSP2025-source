#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[210];
int c,r;
void calc(int x){
	c = x/n;
	if(x%n!=0){
		c++;
		if(c%2==0) r = n-(x%n)+1;
		else r = x%n;
	}
	else{
		if(c%2==0) r=1;
		else r=n;
	}
	return ;
}
int find(int x){
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			return i;
		}
	}
	return -1;
}
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	
	int x = a[1];
	sort(a+1,a+(n*m)+1,cmp);
	calc(find(x));
	printf("%d %d\n",c,r);
	return 0;
}

