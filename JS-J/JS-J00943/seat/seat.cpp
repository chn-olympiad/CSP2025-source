#include<bits/stdc++.h>
using namespace std;
int n,m,r,a=1,an,am;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	for(int i=1,j;i<n*m;i++){
		cin>>j;
		if(j>r) a++;
	}
	am=a/n+min(1,a%n);
	if(am%2==1){
		if(a%n==0) an=n;
		else an=a%n;
	}
	else{
		if(a%n==0) an=n;
		else an=a%n;
		an=n+1-an;
	}
	cout<<am<<" "<<an;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
