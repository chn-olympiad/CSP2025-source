#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("seat.in","r",stdin);
	int a,b;
	cin >>a>>b;
	int n[a+2][b+2]={0},m[101];
	for (int i=1;i<=a;i++){
		for (int x=1;x<=b;x++){
			cin >>n[i][x];
		}
		i++;
		for (int y=b;y>=1;y--){
			cin >>n[i][y];
		}
	}
    for (int i=0;i<=a+1;i++){
		for (int j=0;j<=b+1;j++){
			cout<<n[i][j]<<' ';
			
		}
		cout<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}