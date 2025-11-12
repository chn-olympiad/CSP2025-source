#include<bits/stdc++.h>
using namespace std;
int n,a1[100005],b1[100005],c1[100005],k=1,k1=1,t,d1,d2,d11=3,d22=3,ans=0,an1,an2,a[100005],b[100005];
int a11[100005]={0};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>b1[i]>>c1[i];
			if(b1[i]==0&&c1[i]==0&&k==1) k=1;
			else k=0;
			if(c1[i]==0) k1=1;
			else k=0;
		}
		if(n==2){
			d1=max(a1[1],max(b1[1],c1[1]));
			d2=max(a1[2],max(b1[2],c1[2]));
			if(d1==a1[1]) d11=1;
			else if(d1==b1[1]) d11=2;
			if(d2==a1[2]) d22=1;
			else if(d2==b1[2]) d22=2;
			if(d11!=d22) ans=d1+d2;
			else{
				ans+=max(d1,d2);
				if(d2>=d1){
					a[1]=a1[1],a[2]=b1[1],a[3]=c1[1];
					sort(a+1,a+4);
					ans+=a[2];
				}
				else{
					a[1]=a1[2],a[2]=b1[2],a[3]=c1[2];
					sort(a+1,a+4);
					ans+=a[2];
				}
			}
        }else if(k==1){
        	for(int i=1;i<=n;i++) a[i]=a1[i];
        	sort(a+1,a+n+1);
        	ans=a[n]+a[n-1];
		}
    cout<<ans;
} 
    fclose(stdin);
	fclose(stdout);
	return 0;
}
