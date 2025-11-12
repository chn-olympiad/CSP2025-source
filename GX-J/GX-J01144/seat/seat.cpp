#include<iostream>
using namespace std;
int main(){
	int i,m,n,a[100][100]={},s[1000]={},x,y;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>s[i];
		if(s[i]<s[i+1]){
		s[i]=s[i+1]
		}
		x=1;
		y=1;
		s[i]=a[1][x];
		x++;
		for(int i;i<=m-1;i++){
		if(x==m){
		s[i]=a[y+1][x];
		x--;
		}
		if(x==1){
		s[i]=a[y+1][x];
		x++;
		}
		}
		}
		}
		cout<<s[x][y];
		freopen('r',seat.in)
		freopen('w',seat.out)
		return 0;
	
	}
