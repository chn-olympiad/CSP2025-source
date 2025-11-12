#include<bits/stdc++.h>
using namespace std;
int n,m;
int t;
int a[1007];
int an,as;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) t=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			t=n*m-i+1;
		} 
	}
	if(t%n==0){
		an=t/n;
		if(an%2==1) as=n;
		else as=1;
	}
	else{
		an=t/n+1;
		if(an%2==1) as=t%n;
		else as=n-t%n+1;
		}
		cout<<an<<" "<<as;
	return 0;
} 
