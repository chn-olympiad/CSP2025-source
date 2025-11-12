#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin)
	freopen("club.out","w",stdout)
	int a[100050],b[100050],c[100050],su[100050],s1[100050],s2[100050],bj[100050];
	int i,j,k,n[1005],m=0,s=0,k=0,t,z=0;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n[i];
		for(j=0;j<n[i];j++){
			cin>>a[j]>>b[j]>>c[j];
			su[j]=0;
			s1[j]=0;
			s2[j]=0;
		}
	}
	for(i=0;i<t;i++){
		for(j=0;j<n[i];j++){
			if(a[j]>b[j] && a[j]>c[j]) bj[j]=1;
			if(b[j]>a[j] && b[j]>c[j]) bj[j]=2;
			if(c[j]>a[j] && c[j]>b[j]) bj[j]=3;
		}
	}
	for(i=0;i<t;i++){
		for(j=0;j<n[i];j++){
			if(bj[j]==1) {
				su[j]+=a[j];
				s++;
			}
			if(bj[j]==2) {
				s1[j]+=b[j];
				m++;
			}
			if(bj[j]==3){
				s2[j]+=c[j];
					k++;
			} 
		}
	}
	for(i=0;i<t;i++){
		for(j=0;j<n[i];j++){
			z=su[j]+s1[j]+s2[j];
			if(s<=n/2 && m<=n/2 && k<=n/2) cout<<z<<endl;
		}
	}
	return 0;
}
