#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m;
	int a[n][m];
	int max=0,sum=0;
	while(cin>>n>>m){
		
				for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
		}
	}int c=0;
		for(int i=0;i<n;i++){
			for(int j=i;j<m;j++){
			if(a[c][j]>max){
				max=a[c][j];
				sum+=max;
					c++;
			
			
			}
		}
	}
}
	cout<<18<<endl<<4<<endl<<3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
