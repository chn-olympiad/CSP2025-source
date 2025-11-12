#include<bits/stdc++.h>
using namespace std;
long long a[15][15],b[1000],x,y,t,z;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x*y;i++){
		cin>>b[i];
		if(i==1)t=b[i];
	}
	sort(b+1,b+x*y+1);
	for(int i=1;i<=x*y;i++){
		if(t==b[i])z=i;
	}
	z=x*y-z+1;
	if(z%x==0){
		cout<<z/x<<" ";
		if(z/x%2==1)cout<<x;
		else cout<<1;
	}
	else{
		cout<<z/x+1<<" ";
		if((z/x+1)%2==1)cout<<z%x;
		else cout<<x-z%x+1;
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
