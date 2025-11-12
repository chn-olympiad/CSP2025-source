#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,r=0,c=0;
	cin>>n>>m;
	vector<int>a;
	cin>>r;
	a.push_back(r);
	for(int i=1;i<n*m;i++){
		int x=0;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end(),cmp);
	while(a[c]!=r){
		c++;
	}
	int x=0,y=0;
	x=c/m;
	if(x%2==0)y=c%n+1;
	else y=n-c%n;
	cout<<x+1<<' '<<y;
	return 0;
}  
