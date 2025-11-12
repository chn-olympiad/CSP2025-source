#include<bits/stdc++.h>
using namespace std;
#define N 20005

int n,m,pai,c;
int a[N];

int cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			pai=i;
			break ;
		}
	}
//	cout<<pai<<" ";
	c=pai/n;
	if(pai%n)	c++;
	if(c%2==1){
		cout<<c<<" "<<pai-(c-1)*n;
	}
	else{
		cout<<c<<" "<<n*c-pai+1;
	}
	return 0;
}