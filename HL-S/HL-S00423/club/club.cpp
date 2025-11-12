#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int a1[100005],a2[100005],a3[100005];
bool a(){
	for(int i=1;i<=n;i++){
		if(a2[i]!=0||a3[i]!=0)
			return false;
	}
	return true;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a1[i]>>a2[i]>>a3[i];
		if(a()){
			sort(a1+1,a1+n+1);
			for(int i=n-n/2;i<=n;i++){
				ans+=a1[i];
			}
			cout<<ans;
			continue;
		}
		for(int i=1;i<=n;i++){
			int maxx=INT_MIN;
			maxx=max(a1[i],maxx);
			maxx=max(a2[i],maxx);
			maxx=max(a3[i],maxx);
			if(maxx==a1[i]){ans+=a1[i];}
			else if(maxx==a2[i]){ans+=a2[i];}
			else {ans+=a3[i];}	
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
//Ren5Jei4Di4Ling5%
