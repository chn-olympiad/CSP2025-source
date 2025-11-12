#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[100100][5],outp[10],check1[100100],check2[100100],check3[100100];
	int sub[100100],b1=0,b2=0,b3=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
				
			}
		}
		for(int j=1;j<=n;j++){
			sub[j]=max(a[j][1],max(a[j][2],a[j][3]));
			if(sub[j]==a[j][1])b1++;
			if(sub[j]==a[j][2])b2++;
			if(sub[j]==a[j][3])b3++;
			
		}
		for(int j=1;j<=n;j++){
			check1[j]=a[j][1];
		}
		for(int j=1;j<=n;j++){
			check2[j]=a[j][2];
		}
		for(int j=1;j<=n;j++){
			check3[j]=a[j][3];
		}
		if(b1<=n/2&&b2<=n/2&&b3<=n/2){
				for(int k=1;k<=n;k++)
					outp[t]+=sub[k];
			}
		
}
	for(int i=1;i<=t;i++){
		cout<<outp[t];
	}
	return 0;
}