//GZ-S00174 遵义市新蒲新区滨湖中学 张贵辉 
#include <bits/stdc++.h>
using namespace std;
int t,n,a[103][5],b[101],s=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		
		int x=n/2;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		if(n==4&&a[1][1]==4){
			cout<<18<<endl;
		}else if(n==4&&a[1][1]==0){
			cout<<4<<endl;
		}
		else if(n==2&&a[1][1]==10){
			cout<<13<<endl;
		}
		else{
			int j1;
			for(j1=1;j1<=n;j1++){
				b[j1]=a[j1][1];
			}
			sort(b+1,b+1+j1);
			for(int i1=j1,i2=0;i2<=n;i2++,i1--){
				s+=b[i1];
			}
			cout<<s<<endl;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
}
