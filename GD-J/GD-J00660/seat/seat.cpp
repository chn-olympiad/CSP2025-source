#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,ai=1;
	cin>>n>>m>>a;
	for(int i=0;i<n*m-1;i++){
		int s;
		cin>>s;
		if(s>a){
			ai++;
			//cout<<s<<endl;
		}
	}int x,y;
	//cout<<ai<<endl;
	x=ceil(ai*1.0/n);
	if(x%2==1){
		y=ai%n;
		if(y==0)y=n;
	}
	else y=n-ai%n+1;
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

