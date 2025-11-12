#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,s,score[105],l;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) {
		cin>>score[i];}
	l=score[0];
	sort(score,score+n*m);
	for(int i=n*m-1;i>=0;i--) {
		if(score[i]==l)
			s=n*m-i;
	}
	if(s%n==0) c=s/n;
	else c=s/n+1;
	if(c%2==0){
		if(s%n==0) r=n;//s=7 n=3 
		else r=n-s%n+1;
	}
	else {
		if(s%n==0) r=n;
		else r=s%n;
	}
	cout<<c<<' '<<r;
	return 0;
}
