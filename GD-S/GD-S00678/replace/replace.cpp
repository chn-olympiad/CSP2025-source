#include<bits/stdc++.h>
using namespace std;

long long a[105][105][105][105];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	int n = 100;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;i++){
			for(int l = 1;l<=n;l++){
				for(int f = 1;f<=n;f++){
					cout<<a[i][j][l][f];
					
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
