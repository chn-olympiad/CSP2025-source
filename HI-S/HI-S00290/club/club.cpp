#include<bits/stdc++.h>
using namespace std;

int main(){
//	freopen("club1.in","r",stdin);
//	freopen("club.out","w",stdout);
		int t,n,a,f;
		int max=0,cnt;
		cin>>t>>n;
		for(int i=0;i<=t;i++){
			for(int j=0;j<=n;j++){
				cin>>a;
				if(max<a){
					cnt+=max;
					 max=a;
				}
			}	
		}
		cout<<cnt;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
 
