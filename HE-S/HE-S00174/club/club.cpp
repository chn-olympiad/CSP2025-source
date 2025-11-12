#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	for(int tt=0;tt<t;t++){
		int n=0;
		cin>>n;
		
		int max=0;
		int s[10001][3];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>s[i][j];
				if(s[i][0]>max){
					max=s[i][0];
				}
			}
		}
		cout<<max<<endl;
	}
	
	return 0;
}

