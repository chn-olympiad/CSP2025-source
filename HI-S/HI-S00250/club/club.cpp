#include<bits/stdc++.h>
using namespace std;
int a[10010][60],b[10010][60],p[10010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,cys1=0,cys2=0,cys3=0,cnt=0;cin>>t;
	for(int g=1;g<=t;g++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]&&cys1<=n/2){
				p[i]=a[i][1];
				cys1++;
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]&&cys2<=n/2){
				p[i]=a[i][2];
				cys2++;
			}
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]&&cys3<=n/2){
				p[i]=a[i][3];
				cys3++;
			}
		}
		for(int i=1;i<=n;i++){
			cnt+=p[i];
		}
		cout<<cnt;
	}		
	return 0;
} 
