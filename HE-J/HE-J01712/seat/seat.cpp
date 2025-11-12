#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x[m][n],z=n*m;
	int y[z];
	for(int i=0;i<z;i++){
		cin>>y[i];
	}
	int a=y[0];
	sort(y,y+z);
	for(int i=0;i<z;i++){
		if(y[i]==a&&(i/2)%2==0){
			cout<<a;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
