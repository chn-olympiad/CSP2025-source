#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int l=a[1];
	sort(a+1,a+1+n*m,cmp);
	int z;
	for(int i=1;i<=n*m;i++){
		if(a[i]==l){
			z=i;
			break;
		}
	}
	int x=z/n;
	if(z%m!=0){
		x+=1;
	}
	if(x%2!=0){
		if(z%m==0)
			cout<<x<<" "<<m+z%m<<"\n";
		else 
			cout<<x<<" "<<z%m<<"\n";
	}
	else{
		if(z%m==0)
			cout<<x<<" "<<1+z%m<<"\n";
		else 
			cout<<x<<" "<<m+1-z%m<<"\n";
	}
	return 0;
}
