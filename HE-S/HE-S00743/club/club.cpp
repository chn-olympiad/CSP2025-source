#include<bits/stdc++.h>
using namespace std;
#define maxa 100007
int work(int n){
	int a[maxa][3],pp[maxa],kk[maxa];
	int a1=0,b1=0,c1=0,ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)  cin>>a[i][j];		
	}
	for(int i=1;i<=n;i++){
		if( a[i][1]>=a[i][2] && a[i][1]>=a[i][3] ){
			ans+=a[i][1];
			pp[i]=1;
			a1++;
		}else if( a[i][2]>=a[i][1] && a[i][2]>=a[i][3] ){
			ans+=a[i][2];
			pp[i]=2;
			b1++;
		}else if( a[i][3]>=a[i][1] && a[i][3]>=a[i][2] ){
			ans+=a[i][3];
			pp[i]=3;
			c1++;
		}
	}
	int tt=0;
//------------------------------------------------------
	if(a1>n/2){
		for(int i=1;i<=n;i++){
			if(pp[i]==1){
				tt++;
				kk[tt]=min(a[i][1]-a[i][2] , a[i][1]-a[i][3]);
			}
		}
		sort(kk+1,kk+1+tt);
		while(tt>n/2){
			ans-=kk[a1-tt+1];
			tt--;
		}
	}
//------------------------------------------------------
	if(b1>n/2){
		for(int i=1;i<=n;i++){
			if(pp[i]==2){
				tt++;
				kk[tt]=min(a[i][2]-a[i][1] , a[i][2]-a[i][3]);
			}
		}
		sort(kk+1,kk+1+tt);
		while(tt>n/2){
			ans-=kk[b1-tt+1];
			tt--;
		}
	}
//------------------------------------------------------
	if(c1>n/2){
		for(int i=1;i<=n;i++){
			if(pp[i]==3){
				tt++;
				kk[tt]=min(a[i][3]-a[i][2] , a[i][3]-a[i][1]);
			}
		}
		sort(kk+1,kk+1+tt);
		while(tt>n/2){
			ans-=kk[c1-tt+1];
			tt--;
		}
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n[7],lans[7];
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		lans[i]=work(n[i]);
    }
    for(int i=1;i<=t;i++){
		cout<<lans[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
	return 0;
}

