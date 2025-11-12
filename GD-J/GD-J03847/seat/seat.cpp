#include<bits/stdc++.h>
using namespace std;
int n,m,R,x=1,y=1,seat[11][11];
priority_queue <int> a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int S=m*n;
	for(int i=0;i<S;i++){
		int x;
		cin>>x;
		if(i==0)R=x;
		a.push(x);
	}
	while(!a.empty()){
		if(a.top()==R){
			cout<<x<<' '<<y;
			break;
		}
		if(x%2){
			if(y<n)y++;
			else x++;
		}
		else{
			if(y>1)y--;
			else x++;
		}
		a.pop();
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
