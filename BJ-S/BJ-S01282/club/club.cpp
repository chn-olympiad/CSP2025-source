#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    int n;
    cin>>t>>n;
    int a;
    int ans=0;
    int aid=0;
    for(int i=1;i<=n;i++){
		if(i==1){
			for(int j=1;j<=3;j++){
			cin>>a;
			ans=max(a,ans);
		}
		
	}
	    if(i==2){
			for(int j=1;j<=3;j++){
			cin>>a;
			aid=max(a,aid);
			
		}
		
	}
}
	int sum=ans+aid;
	cout<<sum-1;
    return 0;
    }
