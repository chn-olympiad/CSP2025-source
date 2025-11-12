#include<bits/stdc++.h>
using namespace std;
int s[100005][3];
int a[100005];
int b[100005];
int c[100005];
int a1=0,b1=0,c1=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    	int n,minn=INT_MAX,ans=0,p2=0,p3=0;
    	cin>>n;
		for(int i=1;i<=n;i++){
    	cin>>s[i][1]>>s[i][2]>>s[i][3];	
    	if(s[i][2]==0)
    	p2++;
    	if(s[i][3]==0)
    	p3++;
		}
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int k=1;k<=i-1;k++){
					ans=max(ans,s[1][i]+s[2][k]);
				}
				for(int k=i+1;k<=3;k++){
					ans=max(ans,s[1][i]+s[2][k]);
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(p3==n){
			if(p3==p2){
				for(int i=1;i<=n;i++)
				a[i]=s[i][1];
				sort(a+1,a+1+n);
				for(int i=n;i>=n/2+1;i--)
					ans+=a[i];
					cout<<ans<<endl;
					continue;
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i][1]>=s[i][2]&&s[i][1]>=s[i][3]){
				ans+=s[i][1];
				continue;
			}
			if(s[i][2]>=s[i][1]&&s[i][2]>=s[i][3]){
				ans+=s[i][2];
				continue;
			}
			if(s[i][3]>=s[i][2]&&s[i][3]>=s[i][1]){
				ans+=s[i][3];
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			ans+=a[i]+b[i]+c[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
