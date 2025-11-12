#include<iostream>
#include<vector>
using namespace std;



int main(){
	freopen("D:/GD-S00944/road/road.in","r",stdin);
	freopen("D:/GD-S00944/road/road.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int d[1000][3];
		for(int i=0;i<n;i++){
			cin>>d[i][0]>>d[i][1]>>d[i][2];
		}

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
