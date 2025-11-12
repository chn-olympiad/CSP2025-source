#include<bits/stdc++.h>
using namespace std;
int t,n;
int q,w,e,sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		sum=0;
		for(int j=1;j<=n;j++){
			
			cin>>q>>w>>e;
			sum+=max(max(q,e),max(w,e));
		}
		cout<<sum<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
