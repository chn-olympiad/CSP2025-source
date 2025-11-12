#include<bits/stdc++.h>
using namespace std;
int l,ans[100005],xb=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>l;
	while(l){
		int a[10005][3]={},b[10005][4]={};
		l--;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			b[i][0]=a[i][0]-a[i][1]-a[i][2];
			b[i][1]=a[i][1]-a[i][2]-a[i][0];
			b[i][2]=a[i][2]-a[i][0]-a[i][1];
		}
		int t=n/2;
		while(t){
			t--;
			int mx=-10000000,my=-10000000,mz=-10000000;
			int m1=0,m2=0,m3=0,flag1=0,flag2=0,flag3=0;
			for(int i=1;i<n;i++){
				if(b[i][3]==-1){
					continue;
				}
				if(mx<=b[i][0]&&a[i][0]==max(a[i][0],max(b[i][1],a[i][2]))){
					mx=b[i][0];
					m1=i;
					flag1=1;
				}
			}
			if(flag1){		
				b[m1][3]=-1;
				ans[xb]+=a[m1][0];
			}
			a[m1][0]=0;				
			for(int i=1;i<n;i++){
				if(b[i][3]==-1){
					continue;
				}
				if(my<=b[i][1]&&a[i][1]==max(a[i][0],max(a[i][1],a[i][2]))){
					my=b[i][1];
					m2=i;
					flag2=1;
				}
			}
			if(flag2){
				b[m2][3]=-1;
				ans[xb]+=a[m2][1];		
			}

			a[m2][1]=-1;	
			for(int i=1;i<n;i++){
				if(b[i][3]==-1){
					continue;
				}
				if(mz<=b[i][2]&&a[i][2]==max(a[i][0],max(a[i][1],a[i][2]))){
					mz=b[i][2];
					m3=i;
					flag3=1;
				}
			}
			if(flag3){
				b[m3][3]=-1;
				ans[xb]+=a[m3][2];
			}
			a[m3][2]=0;				
		}
		xb++;
	}
	for(int i=0;i<xb;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 

