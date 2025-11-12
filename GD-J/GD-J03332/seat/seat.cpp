#include<bits/stdc++.h>
using namespace std;
int n,m,k,p[105];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>p[i];
	k=p[1];
	sort(p+1,p+n*m+1,cmp);
	int x=1,y=1,t=0;
	while(1){
		t++;
		if(p[t]==k){
			cout<<y<<" "<<x;
			return 0;
		}
		if(y%2==1){
			if(x==n) y++;
			else x++;
		}
		else{
			if(x==1) y++;
			else x--;
		}
	}
	return 0;
}
