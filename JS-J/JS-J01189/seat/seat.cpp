#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int u[105];
	int h=0;
	for(int i=1;i<=n*m;i++){
		cin>>u[i];
		if(i==1){
			h=u[i];
		}
	}
	int x=0;
	int y=0;
	sort(u+1,u+((n*m)+1),cmp);
	for(int i=1;i<=n*m;i++){
		if(u[i]==h){
			 x=i%n;
			 if(x==0)
			 x=n;
			 y=(i-1)/n+1;
			if(y%2==0){
				x=n-x+1;
			}
		}
	}
	cout<<y<<' '<<x;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
