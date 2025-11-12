#include<bits/stdc++.h>
using namespace std;
int t[11][11];
int z[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,wei=1,lie=0,hang=0,s=0,y=0;
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cin>>z[i];
	}
	for(int i=1;i<=a*b;i++){
		if(i!=1&&z[i]>z[1]){
			wei++;
		}
	}
	s=wei/(2*a);
	y=wei%(2*a);
	lie=2*s;
	if(y==0){
		hang=1;
	}
	else if(y<=a){
		lie+=1;
		hang=y;
	}
	else if(y>a){
		lie+=2;
		hang=2*a-y+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
}