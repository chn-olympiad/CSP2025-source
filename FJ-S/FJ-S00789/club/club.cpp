#include<bits/stdc++.h>
using namespace std;
int it[100005],club1h[50005],club2h[50005],club3h[50005],club1[50005],club2[50005],club3[50005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for (int h=0;h<t;h++){
		int n,ans=0,club1r=0,club2r=0,club3r=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>club1h[i]>>club2h[i]>>club3h[i];
		}
		for (int g=0;g<n;g++){
			int mex=club1h[g],mexx=1;
			if (mex<club2h[g]){
				mex=club2h[g];
				if (club2r<=n/2){
					mexx=2;
				}else if(club3r<=n/2){
					mexx=3;
				}else{
					mexx=1;
				}
			}else if(mex<club3h[g]){
				mex=club3h[g];
				if (club3r<=n/2){
					mexx=3;
				}else if(club2r<=n/2){
					mexx=2;
				}else{
					mexx=1;
				}
			}
			if (mexx==1){
				ans=ans+club1h[g];
				club1r++;
			}else if (mexx==2){
				ans=ans+club2h[g];
				club2r++;
			}else if (mexx==3){
				ans=ans+club3h[g];
				club3r++;
			}
		}
		cout<<ans;
	}
	
	return 0;
}
