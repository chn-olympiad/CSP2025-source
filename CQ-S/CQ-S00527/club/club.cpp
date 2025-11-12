#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,c,ans,s[3][100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>T;
	while(T--){
		ans=s[0][0]=s[1][0]=s[2][0]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				s[0][++s[0][0]]=a-max(b,c);
				ans+=a;
			}else if(b>=a&&b>=c){
				s[1][++s[1][0]]=b-max(a,c);
				ans+=b;
			}else if(c>=a&&c>=b){
				s[2][++s[2][0]]=c-max(a,b);
				ans+=c;
			}
		}
		if(s[0][0]>n/2){
			sort(s[0]+1,s[0]+s[0][0]+1);
			for(int i=1;i<=(s[0][0]-n/2);i++){
				ans-=s[0][i];
			}
		}
		if(s[1][0]>n/2){
			sort(s[1]+1,s[1]+s[1][0]+1);
			for(int i=1;i<=(s[1][0]-n/2);i++){
				ans-=s[1][i];
			}
		}
		if(s[2][0]>n/2){
			sort(s[2]+1,s[2]+s[2][0]+1);
			for(int i=1;i<=(s[2][0]-n/2);i++){
				ans-=s[2][i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}



/*
I'm Wrong_Accept,but I only get *** points
CCF is slove() and CCF is froepen("club3.out","r",stdin);
*/
