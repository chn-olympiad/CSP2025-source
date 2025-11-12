#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	cin>>t;
	while(t--){
		int a[100010]={},b[100010]={},c[100010]={}; 
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		if(n==2){
			int maxn=a[1]+b[2];
			if(a[1]+c[2]>=maxn) maxn=a[1]+c[2];
			if(b[1]+a[2]>=maxn) maxn=b[1]+a[2];
			if(b[1]+c[2]>=maxn) maxn=b[1]+c[2];
			if(c[1]+a[2]>=maxn) maxn=c[1]+a[2];
			if(c[1]+b[2]>=maxn) maxn=c[1]+b[2];
			cout<<maxn<<endl;
		}
		else{
			int m1=0,m2=0,m3=0;
			for(int k=n;k>=1;k--){
				m1=max(m1,a[k]);
				m2=max(m2,b[k]);
				m3=max(m3,c[k]);
			}
			int sum=m1+m2+m3+max(m2,max(m1,m3));
			if(sum%2==1){
				cout<<sum-1<<endl;
			}
			else{
				cout<<sum<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
