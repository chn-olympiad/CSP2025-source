#include<bits/stdc++.h>
using namespace std;
int grade[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	int n,m,a,b,c,d,r;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>grade[i];
	}
	r=grade[1];
	sort(grade+1,grade+m*n+1);
	a=lower_bound(grade+1,grade+m*n+1,r)-grade;
	b=m*n-a+1;
	c=b/n;
	d=b%n;
	if(c%2==0){
		if(d==0){
			cout<<c<<" "<<1;
		}
		else{
			cout<<c+1<<" "<<d;
		}
	}
	else{
		if(d==0){
			cout<<c<<" "<<n;
		}
		else{
			cout<<c+1<<" "<<n-d+1;
		}
	}
	return 0;
}
