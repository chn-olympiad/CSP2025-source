#include<bits/stdc++.h>
using namespace std;
int a[150];
int n, m;
int c, r;
int num; 
bool cmp(int x, int y){
	return x>y;
}


int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	int sc=a[1];
	sort(a+1, a+n*m+1, cmp);
	
	for(int i=1; i<=n*m; i++){
		if(a[i]==sc){
			num=i;
		}
	}
	c=num/n; 
	if(num%n!=0){
		c++;
	}
	r=num%n;
	if(r==0){
		r=n;
	}
	if(c%2==0){
		r=n+1-r;
	}
	cout<<c<<" "<<r<<"\n";
	




    return 0;
}
