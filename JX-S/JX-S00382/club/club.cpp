#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	
	cin>>t;
	for(int a=1;a<=t;a++){
		cin>>n;
		int s[n][3],sum=0,max=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>s[i][j];
				
				if(s[i][j]>max){max=s[i][j];}
				
			}
			sum+=max;
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
