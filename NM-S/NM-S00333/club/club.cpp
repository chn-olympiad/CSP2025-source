#include<bits/stdc++.h>
using namespace std;
long long maxx,n,t,a1[110000],a2[110000],a3[110000],a41[110000],a42[110000],a43[110000],cnt,m1,m2,m3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cnt=0,m1=0,m2=0,m3=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a1[j]>>a2[j]>>a3[j];
			cnt+=max(a1[j],max(a2[j],a3[j]));
			if(a1[j]>a2[j]&&a1[j]>a3[j]){
				m1++;
				a41[m1]=a1[j]-max(a2[j],a3[j]);
			}
			else if(a2[j]>a3[j]){
				m2++;
				a42[m2]=a2[j]-max(a1[j],a3[j]);
			}
			else{
				m3++;
				a43[m3]=a3[j]-max(a2[j],a1[j]);
			}
		}
		maxx=max(m1,max(m2,m3));
		if(maxx<=(n/2)){
			cout<<cnt<<endl;
		}else{
			if(m1>m2&&m1>m3){
				sort(a41+1,a41+m1+1);
				for(int l=1;l<=m1-(n/2);l++){
					cnt-=a41[l];
				} 
			}
			else if(m2>m3){
				sort(a42+1,a42+m2+1);
				for(int l=1;l<=m2-(n/2);l++){
					cnt-=a42[l];
				} 
			}
			else{
				sort(a43+1,a43+m3+1);
				for(int l=1;l<=m3-(n/2);l++){
					cnt-=a43[l];
				} 
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
