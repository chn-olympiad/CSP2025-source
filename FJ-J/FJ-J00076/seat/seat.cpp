#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,a[105];
bool cmp(int a,int b){return a>b;}
//fuckyou
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=n*m;
	for(int i=1;i<=p;i++){
		scanf("%d",a+i);
	}
	a[0]=a[1];
	sort(a+1,a+p+1,cmp);
	int i=0;
	for(i=1;a[i]!=a[0];i++);
	c=i/n;
	if(i%n)c+=1;
	if(c%2==1){
		r=i%n;
		if(i%n==0)r=n;
	}else{
		r=n-(i%n)+1;
		if(i%n==0)r=1;
	}
	cout<<c<<' '<<r;
	fclose(stdin);fclose(stdout);
}
