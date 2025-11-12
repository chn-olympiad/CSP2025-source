#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int a1[100005],b1[100005],c1[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
	    int an1,an2,an3;
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++){
			a1[i]=a[n+1-i];
			b1[i]=b[n+1-i];
			c1[i]=c[n+1-i];	
		}
		for(int i=1;i<=n;i++){
		    an1+=a1[i];
			an2+=b1[i];
			an3+=c1[i];
			cout<<a1[i]<<" "<<b1[i]<<" "<<c1[i]<<endl;
		}
		int ma=max(an1,max(an2,an3));
		for(int i=1;i<=n/2;i++){
			if(ma==an1){
				ans+=a1[i];
				a1[i]=0;
			}
			if(ma==an2){
				ans+=b1[i];
				b1[i]=0;
			}
			if(ma==an3){
				ans+=c1[i];
				c1[i]=0;
			}
		}
		cout<<ans<<" ";
		if(ma=an1){
			an1=0;
		}
		if(ma=an2){
			an2=0;
		}
		if(ma=an3){
			an3=0;
		}
		n/=2;
		if(n==1) n=2;
		int ma2=max(an1,max(an2,an3));
		for(int i=1;i<=n/2;i++){
			if(ma2==an1){
				ans+=a1[i];
				a1[i]=0;
			}
			if(ma2==an2){
				ans+=b1[i];
				b1[i]=0;
			}
			if(ma2==an3){
				ans+=c1[i];
				c1[i]=0;
			}
		}
		cout<<ans<<" ";
		if(ma2=an1){
			an1=0;
		}
		if(ma2=an2){
			an2=0;
		}
		if(ma2=an3){
			an3=0;
		}
		n=n/2;
		if(n==1) n=2;
		int ma3=max(an1,max(an2,an3));
		for(int i=1;i<=n/2;i++){
			if(ma3==an1){
				ans+=a1[i];
				a1[i]=0;
			}
			if(ma3==an2){
				ans+=b1[i];
				b1[i]=0;
			}
			if(ma3==an3){
				ans+=c1[i];
				c1[i]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
