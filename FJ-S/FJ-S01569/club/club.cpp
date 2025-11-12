#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a,b,c,p1[N],p2[N],p3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			ans+=max(max(a,b),c);
			if(a>=b && a>=c)
				p1[++cnt1]=a-max(b,c);
			else if(b>=a && b>=c)
				p2[++cnt2]=b-max(a,c);
			else
				p3[++cnt3]=c-max(a,b);
		}
		if(max(max(cnt1,cnt2),cnt3)<=n/2)
			cout<<ans<<"\n";
		else{
			if(cnt1>cnt2 && cnt1>cnt3){
				sort(p1+1,p1+cnt1+1);
				for(int i=1;i<=cnt1-n/2;i++)
					ans-=p1[i]; 
			}else if(cnt2>cnt1 && cnt2>cnt3){
				sort(p2+1,p2+cnt2+1);
				for(int i=1;i<=cnt2-n/2;i++)
					ans-=p2[i];
			}else{
				sort(p3+1,p3+cnt3+1);
				for(int i=1;i<=cnt3-n/2;i++)
					ans-=p3[i];
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
