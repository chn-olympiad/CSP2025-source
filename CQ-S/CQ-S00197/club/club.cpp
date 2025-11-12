#include <bits/stdc++.h>
using namespace std;
//dp[i][j]  = dp[1][j]+dp[j][1];
int a1[100005],a2[100005],a3[100005];
int T,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int s1=0,s2=0,s3=0,ans=0;
		memset(a1,sizeof(a1),0);
		memset(a2,sizeof(a2),0);
		memset(a3,sizeof(a3),0);
		cin>>n;
		for(int i =1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		int a = n/2;
		int i = 1;
		while(s1+s2+s3<=n){
			if(max(a1[i],max(a2[i],a3[i]))==a1[i] && s1<=a){
				ans+=a1[i];
				s1++;
			}
			else if(max(a2[i],max(a1[i],a3[i]))==a2[i]&& s2<=a){
				ans+=a2[i];
				s2++;
			}
			else if(max(a3[i],max(a2[i],a1[i]))==a3[i]&& s3<=a){
				ans+=a3[i];
				s2++;
			}
			i++;
		}
		cout<<ans<<endl;
	}
	return 0;
}


