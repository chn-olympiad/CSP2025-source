#include <bits/stdc++.h>
using namespace std;
int d[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>d[i];
	}
	int x=d[0];
	int p=0;
	sort(d,d+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(d[i]==x){
			p=i;
			break;
		}
	}
	p++;
	int a=p/n+(p%n!=0),b=p%n;
	if(b==0) b=n;
	if(a&1){
		cout<<a<<" "<<b;
	}
	else{
		cout<<a<<" "<<n-b+1;
	}
	return 0;
}
