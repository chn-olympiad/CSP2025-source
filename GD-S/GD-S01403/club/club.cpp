#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	long long a=-1,b=-2;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		int value[n+5][4];
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>value[j][k];
				if(k==1 and value[j][k]!=0){
					if(value[j][k]>a) a=value[j][k];
					else if(value[j][k]>b) b=value[j][k];
				}
			}
		}
	}
	cout<<a+b;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
