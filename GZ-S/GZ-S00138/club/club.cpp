//GZ-S00138   кнк╪сс 
#include <bits/stdc++.h>
using namespace std;
int s[101][101];
int main(){
	int n,c=0;
	cin>>n;
	int max=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>s[i][j];
		}
	}
	for(int i=0;i<n;i++){
	
		for(int j=0;j<3;j++){
			if(max<s[i][j]){
				max=s[i][j];
			}
		}
		c=c+max;
		max=0;
	}
	cout>>c;
}

