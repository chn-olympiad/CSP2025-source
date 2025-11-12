#include<bits/stdc++.h>
using namespace std;
long long n,q,m,mm,l,r,ll,rr,ta,tb,tta,ttb,ans,p=131,moda=1e9+7,modb=1e9+9,pa[5000005],pb[5000005],a[200005],b[200005],aa[200005],bb[200005];
string s[200005],ss[200005],t,tt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q,pa[0]=pb[0]=1;
	for(int i=1;i<=5000000;i++)pa[i]=pa[i-1]*p%moda,pb[i]=pb[i-1]*p%modb;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
		for(int j=0;j<s[i].size();j++)a[i]=(a[i]*p+s[i][j])%moda,b[i]=(b[i]*p+s[i][j])%modb;
	    for(int j=0;j<ss[i].size();j++)aa[i]=(aa[i]*p+ss[i][j])%moda,bb[i]=(bb[i]*p+ss[i][j])%modb;
	}
	while(q--){
		cin>>t>>tt,ans=0;
		if(t.size()==tt.size()){
			m=t.size(),t="."+t,tt="."+tt,l=1e9,r=0;
			for(int i=1;i<=m;i++)
				if(t[i]!=tt[i])
				    l=min(l,i+0ll),r=max(r,i+0ll);
			for(int i=1;i<=n;i++)
				if(r-l<=s[i].size()&&s[i].size()<=m){
					mm=s[i].size(),ll=max(1ll,r-mm+1),rr=ll+mm-1,ta=tb=tta=ttb=0;
					for(int j=ll;j<=rr;j++)ta=(ta*p+t[j])%moda,tb=(tb*p+t[j])%modb,tta=(tta*p+tt[j])%moda,ttb=(ttb*p+tt[j])%modb;
					while(rr<=m&&ll<=l){
						if(ta==a[i]&&tb==b[i]&&tta==aa[i]&&ttb==bb[i])ans++;
						ta=(ta*p-t[ll]*pa[mm]%moda+moda+t[rr+1])%moda;
						tb=(tb*p-t[ll]*pb[mm]%modb+modb+t[rr+1])%modb;
						tta=(tta*p-tt[ll]*pa[mm]%moda+moda+tt[rr+1])%moda;
						ttb=(ttb*p-tt[ll]*pb[mm]%modb+modb+tt[rr+1])%modb;
						ll++,rr++;
					}
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}
