#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
pii l[100010];
signed main(){
        freopen("club.in","r",stdin);
        freopen("club.out","w",stdout);
        int t=0;
        int a[100010],b[100010],c[100010];
        cin>>t;
        for(int i=1;i<=t;i++){
			int n=0,ans=0,d=0;
			int cnta=0,cntb=0,cntc=0,cntm=0;
			cin>>n;
			if(n==2){
				int x[3],y[3];
				for(int z=1;z<=3;z++)cin>>x[z];
				for(int z=1;z<=3;z++)cin>>y[z];
				sort(x+1,x+3);sort(y+1,y+3);
				 if(max(x[1],max(x[2],x[3]))!=max(y[1],max(y[2],y[3]))){
					ans=max(x[1],max(x[2],x[3]))+max(y[1],max(y[2],y[3]));
					cout<<ans<<endl;
				}
				else{
				
				int ans1=x[1]+y[2];
				int ans2=x[2]+y[1];
				ans=max(ans1,ans2);
				cout<<ans<<endl;
			    }
			    }
			else{
			for(int k=1;k<=n;k++){
			cin>>a[k]>>b[k]>>c[k];
		    if(a[k]==b[k]&&b[k]==c[k]){
				cnta++;l[d++]=make_pair(a[k],b[k]);ans+=a[k];
				}
				
				if(a[k]>b[k]&&b[k]==c[k]){
				cnta++;l[d++]=make_pair(a[k],b[k]);ans+=a[k];
			    }
			    if(a[k]>b[k]&&b[k]>c[k]){
				cnta++;l[d++]=make_pair(a[k],b[k]);ans+=a[k];
			    }
			    if(a[k]>c[k]&&c[k]>b[k]){
				cnta++;l[d++]=make_pair(a[k],c[k]);ans+=a[k];
			    }
			    
				if(b[k]>a[k]&&a[k]==c[k]){
				cntb++;l[d++]=make_pair(b[k],a[k]);ans+=b[k];
				}
				if(b[k]>a[k]&&a[k]>c[k]){
				cntb++;l[d++]=make_pair(b[k],a[k]);ans+=b[k];
				}
				if(b[k]>c[k]&&c[k]>a[k]){
				cntb++;l[d++]=make_pair(b[k],c[k]);ans+=b[k];
				}
				
				if(c[k]>a[k]&&a[k]==b[k]){
				cntc++;l[d++]=make_pair(c[k],a[k]);ans+=c[k];
				}
				if(c[k]>a[k]&&a[k]>b[k]){
				cntc++;l[d++]=make_pair(c[k],a[k]);ans+=c[k];
				}
				if(c[k]>b[k]&&b[k]>a[k]){
				cntc++;l[d++]=make_pair(c[k],b[k]);ans+=c[k];
			}
		}	
		cntm=max(cnta,max(cntb,cntc));
		sort(l+1,l+n+1);
		if(cntm<=n/2){
			cout<<ans<<endl;
			}
			else{
			int duo=cntm-(n/2);
			for(int p=n;n-p<=duo;p--){
			    ans-=l[p].first-l[p].second;
			    cout<<ans<<endl;
			    
			    }
			}
		}
	}	
return 0;
}

				
