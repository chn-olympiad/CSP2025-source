#include<bits/stdc++.h>
using namespace std;
int m,n;
int test[105];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a1;
	for(int i=1;i<=n*m;i++){
		cin>>test[i];
	}
	a1=test[1];
	sort(test+1,test+1+n*m,cmp);
	int i1=0;
	for(int i=1;i<=n*m;i++){
		if(test[i]==a1){
			i1=i;
			break;
		}
	}
	int c,r;
	if(i1%n==0){
		c=i1/n;
		if((i1/n)%2==0){
			r=1;
		}else{
			r=n;
		}
	}else{
		c=i1/n;
		int j=i1-c*n;
		if((c+1)%2==0)r=n-(j-1);
		else r=j;
		c++;
	}
	cout<<c<<" "<<r;
	return 0;
}
