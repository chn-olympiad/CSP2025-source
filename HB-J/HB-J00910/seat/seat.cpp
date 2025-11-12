#include <bits/stdc++.h>
using namespace std;
int a[20][20],b[1001];
bool qw(int s,int t){
	return s>t;
}
int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	int m,n,y=1;
	cin>>n>>m;
	cin>>b[1];
	int d=b[1];
	for(int i=2;i<=n*m;i++){
		cin>>b[i];
	}
	sort(b+1,b+1+n*m,qw);
	int i=1;
	for(int x=1;x<=m;x++){
		for(int j=1;j<=n;j++){
			if(b[i]==d){
				cout<<x<<" "<<y;
				return 0;
			}
			if(x%2==0){
				y--;
			}else{
				y++;
			}
			i++;
		}
		
		
	}
	return 0;
}
