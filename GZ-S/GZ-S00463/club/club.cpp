//GZ-S00463 六盘水市第四实验中学 陈子轩 
#include<bits/stdc++.h>
using namespace std;
int n,a[1000005][5],t,m,sum=0,p=1,p1=1,ma=-1,ma2=-1,ip,po=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		ma=-1;
		ma2=-1;
		sum=0;
		p=1;
		p1=1;
		ip=0;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				if(a[i][2]!=0){
					p=0;
					p1=0;
				}
				else if(a[i][1]!=0){
					p=0;  //p1 1 B
				}
			}
		}
		if(p==1){
			for(int i=0;i<n;i++){
				ma=max(ma,a[i][0]);
			}
			cout<<ma<<endl;
			continue;
		}
		else if(p1==1){
			for(int i=0;i<n;i++){
				if(ma<a[i][0]){
					ip=i;
					ma=a[i][0];
				}
			}
			for(int i=0;i<n;i++){
				if(ma2<a[i][1]&&ip!=i){
					ma2=a[i][1];
				}
			}
			
			int ui=ma+ma2;
			for(int i=0;i<n;i++){
				if(ma2<a[i][1]){
					ip=i;
					ma2=a[i][1];
				}
			}
			for(int i=0;i<n;i++){
				if(ma<a[i][0]&&ip!=i){
					ma=a[i][0];
				}
			}
			ui=max(ui,ma+ma2);
			cout<<ui<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			for(int j=1;j<3;j++){
				if(a[i][j]!=0){
					p=0;
					i=n;
					break;
				}
			}
		}
		if(p==1){
			for(int i=0;i<n;i++){
				ma=max(ma,a[i][0]);
			}
			cout<<ma;
			return 0;
		}
		for(int i=0;i<n;i++){
			m=-1;
			for(int j=0;j<3;j++){
				m=max(m,a[j][i]);
			}
			sum+=m;
		}
	cout<<sum<<endl;
	}
	return 0;
}
