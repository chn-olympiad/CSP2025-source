#include<bits/stdc++.h>
using namespace std;
int n,m,r,a[100005],z,f,b,c;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	f=n*m;
	for(int i=1;i<=f;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+f+1,cmp);
	for(int i=1;i<=f;i++){
		if(a[i]==r){
			z=i;
			break;
		}
	}
	b=z/n;
	c=z%n;
	if(b%2==1&&c!=0){
		cout<<b+1<<" "<<n-c+1;
	}else if(b%2==0&&c!=0){
		cout<<b+1<<" "<<c;
	}else if(b%2==1){
		cout<<b<<" "<<n;
	}else{
		cout<<b<<" "<<1;
	}
	return 0;
} 
