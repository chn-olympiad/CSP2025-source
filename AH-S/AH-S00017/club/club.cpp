#include<bits/stdc++.h>
using namespace std;
int a[100005][11];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
		priority_queue<int,vector<int>,greater<int> > cc,aa,bb;
		int n;
		long long ans=0;
		int j[4];
		j[1]=0;
		j[2]=0;
		j[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int s1,s2,s3;
			cin>>s1>>s2>>s3;
			if(s1>=s2&&s1>=s3){
				a[i][1]=s1;
				a[i][2]=1;
				if(s2>=s3) a[i][3]=s2;
				else a[i][3]=s3;
			}
			else if(s2>=s1&&s2>=s3){
				a[i][1]=s2;
				a[i][2]=2;
				if(s1>=s3) a[i][3]=s1;
				else a[i][3]=s3;
			}
			else {
				a[i][1]=s3;
				a[i][2]=3;
				if(s2>=s1) a[i][3]=s2;
				else a[i][3]=s1;
			}
			a[i][7]=a[i][1]-a[i][3];
		}
		for(int i=1;i<=n;i++){
			if(j[a[i][2]]<n/2) {
				ans+=a[i][1];
				j[a[i][2]]++;
				if(a[i][2]==3)
			    cc.push(a[i][7]);
			    else if(a[i][2]==2) bb.push(a[i][7]);
			    else aa.push(a[i][7]);
			}
			else {
			    if(!cc.empty()&&cc.top()<a[i][7]&&a[i][2]==3) {
					int hh=cc.top();
					ans=ans-hh+a[i][1]; 
					cc.pop();	
					cc.push(a[i][7]);
		    	}
		    	else if(!bb.empty()&&bb.top()<a[i][7]&&a[i][2]==2) {
					int hh=bb.top();
					ans=ans-hh+a[i][1]; 
					bb.pop();	
					bb.push(a[i][7]);
		    	}
		    	else if(!aa.empty()&&aa.top()<a[i][7]&&a[i][2]==1) {
					int hh=aa.top();
					ans=ans-hh+a[i][1]; 
					aa.pop();	
					aa.push(a[i][7]);
		    	}
		    	else {
					ans+=a[i][3];
				}
	    	}    
		}
		cout<<ans<<endl;
	}
    return 0;
}
