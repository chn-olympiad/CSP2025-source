#include <iostream>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R;
	int seat[11][11],grade[110];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>grade[i];
	}
		R=grade[1];
		for(int i=1;i<n*m;i++){
			for(int j=1;j<n*m;j++){
			if(grade[j]<grade[j+1]){
				swap(grade[j],grade[j+1]);
			}
			}
	}


	int num=1,flag=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				if(grade[num]==R){
				cout<<i<<" "<<j<<endl;
				flag=1;
			}
			}
			if(i%2==0){
				if(grade[num]==R){
					cout<<i<<" "<<n+1-j<<endl;
					flag=1;
				}
			}
			num++;
			if(flag) break;
		}
		if(flag) break;
	}
	fclose(stdin);
	fclose(stdout);		
	return 0;
}
