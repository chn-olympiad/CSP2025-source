#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans;
	cin>>t>>n>>ans;
	for(int i=1;i<=n;i++){
		int a,a1,a2,a3,ans1=0,ans2=0,ans3=0;
		cin>>a>>a1>>a2>>a3;
		while(i<=n){
		    if(a1>a2&&a3){
		    	ans1=a1;
		    }
		    if(a2>a1&&a3){
		    	ans2=a2;
		    }
		    else{
		    	ans3=a3;
		    }
		i++;
		ans=ans1+ans2+ans3;
		}
	}
	cout<<ans<<endl;
	return 0;
}
