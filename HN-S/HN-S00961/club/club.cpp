#include <bits/stdc++.h>
using namespace std;
long long amax[100010],amax2[100010],t,n,a[3],ax[100010],cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt=0;
		a[0]=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
		for(int i=1;i<=n;i++){
			amax[i]=0;
			ax[i]=0;
			amax2[i]=2147483647;
		}
		for(int i=1;i<=n;i++){
			cin>>a[1]>>a[2]>>a[3];
			amax[i]=max(a[1],max(a[2],a[3]));
			cnt+=amax[i];
			if(amax[i]==a[1]) ax[i]=1;
			else if(amax[i]==a[2]) ax[i]=2;
			else ax[i]=3;
			for(int j=1;j<=3;j++){
				if(j==ax[i]) continue;
				amax2[i]=min(abs(amax[i]-a[j]),amax2[i]);
			}
		}
		long long x1=0,x2=0,x3=0,x=1;
		for(int i=1;i<=n;i++){
			if(ax[i]==1) x1++;
			else if(ax[i]==2) x2++;
			else x3++;
		}
		if(x1>n/2){
			sort(amax2+1,amax2+1+x1);
			while(x1>n/2){
				x1--;
				cnt-=amax2[x++];
			}
		}else if(x2>n/2){
			sort(amax2+1,amax2+1+x2);
			while(x2>n/2){
				x2--;
				cnt-=amax2[x++];
			}
		}else if(x3>n/2){
			sort(amax2+1,amax2+1+x3);
			while(x3>n/2){
				x3--;
				cnt-=amax2[x++];
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}
