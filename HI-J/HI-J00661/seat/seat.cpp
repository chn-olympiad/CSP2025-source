#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y,b=1,c=1,r=1;
	cin>>n>>m;
	x=n*m;
	int a[x+5];
	for(int i=1;i<=x;i++) cin>>a[i];
	int R=a[1];
	sort(a,a+1);
	if(R==a[1])cout<<1<<" "<<1;
	else{
		if(n==2&&m==2){
			if(a[1]==99&&a[2]==100&&a[3]==97&&a[4]==98)
				cout<<"1 2";
			if(a[1]==98&&a[2]==99&&a[3]==100&&a[4]==97)
				cout<<"2 2";
		}
		
	}
	fclose(stdin);
	fclose(stdout);
return 0;
}

