#include<bits/stdc++.h>
using namespace std;
int s[150];

bool cmp(int a, int b){
	return a>b;
}

int main(){
	int n,m,k,fl,c,r;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>s[i];
	}
	k=s[1];
	sort(s+1,s+1+n*m,cmp);
	for(int i=1; i<=n*m; i++){
		if(s[i]==k){
			fl=i;
			break;
		}
	}
	
	c=fl/n+1;
	if(fl%n==0){
		c=fl/n;
		r=n;
	}
	else if(c&1){
		r=(fl+n)%n;
	}
	else{
		r=n-((fl+n)%n)+1;
	}
	cout<<c<<" "<<r<<'\n';
	return 0;
}
