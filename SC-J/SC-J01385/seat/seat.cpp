#include<bits/stdc++.h>
using namespace std;

int n,m;
int num[200];
int s;



int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<n*m;i++){
		cin>>num[i];
	}
	sort(num+1,num+n*m);
	int p=upper_bound(num+1,num+n*m,s)-num-1;
	
	p=n*m-1-p;
	int c=p/n+1;
	int r;
	p++;
	if(c%2==0){
		r=n-((p%n==0)?n:p%n)+1;
	}else{
		r=((p%n==0)?n:p%n);
	}
	cout<<c<<' '<<r;
	return 0;
}