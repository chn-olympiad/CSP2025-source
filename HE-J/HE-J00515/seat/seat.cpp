#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int marks[101]={};
	int n,m;
	int R;
	cin>>n>>m;
	cin>>R;
	for(int i=1,tmp;i<n*m;++i){
		cin>>tmp;
		marks[tmp]++;
	}
	int x=1,y=1,flag=1;
	for(int i=100;i>=R;--i){
		if(marks[i]){
			y+=flag;
		}
		if(y>n){
			y=n;
			++x;
			flag=-flag;
		}
		if(y<1){
			y=1;
			++x;
			flag=-flag;
		}
	}
	cout<<x<<' '<<y;
	return 0;
} 
