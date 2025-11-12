#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int a[N][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
            }
            int r1=0,r2=0,r3=0,cnt1=0,cnt2=0;
            cnt1=max(a[i][1],a[i][2]);
            cnt2=max(a[i][3],cnt1);
            if(cnt2>cnt1&&cnt1>a[i][1]){
                if(r3+1<=n/2){
				   r3++;
			       ans+=cnt2;
			    }
			    else{
				    if(r2+1<=n/2){
			    		r2++;
				    	ans+=cnt1;
				    }
				    else{
					    if(r1+1<=n/2){
				    	r1++;
				    	ans+=a[i][1];
				    	}
			    	}
				}
			}	
			cnt1=0,cnt2=0,r1=0,r2=0,r3=0;	
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
