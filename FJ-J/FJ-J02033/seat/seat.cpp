#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,p;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    int b=n*m;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+b,cmp);
	for(int i=1;i<=b;i++){
		if(a[i]==r){
			p=i;
			break;
		}
	}
	int l=p/n,h;
	if(l%2==0&&p%n!=0)h=p%n;
	else if(l%2==0&&p%n==0)h=1;
	else if(l%2==1&&p%n==0)h=n;
	else h=n-p%n+1;
	if(p%n!=0){
		l+=1;
	}
	cout<<l<<" "<<h;
	return 0;
}
