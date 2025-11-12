#include <bits/stdc++.h>
using namespace std;
int v[101][101],a,b,c[101],d;
char f='D';
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cin>>c[i];
	}
	d=c[1];
	sort(c+1,c+1+a*b,cmp);
	int i=1,j=1;
	for(int x=1;x<=a*b;x++){
		v[i][j]=c[x]; 
		if(f=='D'){
			if(i+1<=a){
				i++;
			}
			else{
				j++;
				f='U';
			}
		}
		else if(f=='U'){
			if(i-1>=1){
				i--;
			}
			else{
				j++;
				f='D';
			}
		}
	}
	for(int x=1;x<=a;x++){
		for(int y=1;y<=b;y++){
			if(v[x][y]==d){
				cout<<y<<" "<<x;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
