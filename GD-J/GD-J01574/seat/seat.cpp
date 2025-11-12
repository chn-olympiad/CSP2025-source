#include<bits/stdc++.h> 
using namespace std;
int n,m,qq[1100],a,b;
bool qw(int a,int b){
	return a>=b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	qq[1]=a;
	b=n*m;
	for(int i=2;i<=b;i++){
		cin>>qq[i];
	}
	sort(qq+1,qq+b+1,qw);
	int x=1,y=1;
	bool f=1;
	for(int i=1;i<=b;i++){
		//cout<<qq[i];
		//cout<<f; 
		if(qq[i]==a){
			cout<<x<<" "<<y;
			return 0;
		}
		if((y==1&&x!=1&&!f)||(y==n&&f)){
			x++;
			if(f)f=0;
			else f=1;
		}
		else if(f){
			y++;
		}else{
			y--;
		}
	}
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

*/
