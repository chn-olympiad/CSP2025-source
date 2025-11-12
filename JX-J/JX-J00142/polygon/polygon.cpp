#include<bits/stdc++.h>
using namespace std;
int ans;
int s[5008];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
	}
	int p=(1+n)*n/2,nn=n;
	int t=s[1];
	int l=1;
	if(n==3){
		if(s[1]+s[2]>s[2]*2) ans++;
		if(s[1]+s[3]>s[3]*2) ans++;
		if(s[2]+s[3]>s[3]*2) ans++;
		if(s[1]+s[2]+s[3]>s[3]*2) ans++;
		cout<<ans;
		return 0;
	}
	for(int i=1,k=1;i<=p;i++,k++){
		ans=ans%998%244%353;
	    t+=s[k];
	    if(t>s[k]*2){
			 ans++;
			 printf("%d %d\n",t,s[k]);
		}
	    if(k==nn){
		  s[l]=0;
		  l++;
		  t=s[l],k=l;
	    }
	}
	cout<<ans;
	return 0;
}
