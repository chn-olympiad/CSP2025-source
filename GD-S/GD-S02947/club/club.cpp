#include<bits/stdc++.h>
using namespace std;
int T,n,p[100005];
bool flag;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			p[i]=a;
			if(c!=0||b!=0) flag=true;
		}
		if(!flag){
			sort(p+1,p+1+n);
			int ans=0;
			for(int i=n;i>=n/2;i--){
				ans+=p[i];
			}
			cout<<ans;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
