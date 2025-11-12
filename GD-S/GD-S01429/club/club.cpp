#include<bits/stdc++.h> 
using namespace std;

int t,n,a[100005],b,c,ans;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int i=1;i<=t;i++){
		n=0,ans=0;
		memset(a,0,100005*4);
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b>>c;
		}
		sort(a+1,a+n+1);
		for(int j=n;j>n/2;j--){
			ans+=a[j];
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
