#include <bits/stdc++.h>
using namespace std;
int t,a1[100002],a2[100002],a3[100002],s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int a100=0;a100<t;a100++){
		s=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i];
			cin>>a2[i];
			cin>>a3[i];
		}
		int max1,max2,max3,p1,p2,p3,n1=0,n2=0,n3=0;
		if(n<=2){
			int zzz1,zzz2,zzz3,zzz4,zzz5,zzz6;
			zzz1=a1[1]+a2[2];
			zzz2=a1[1]+a3[2];
			zzz3=a2[1]+a1[2];
			zzz4=a2[1]+a3[2];
			zzz5=a3[1]+a1[2];
			zzz6=a3[1]+a2[2];
			cout<<max(max(max(max(max(zzz1,zzz2),zzz3),zzz4),zzz5),zzz6);
			return 0;
		}
		for(int i=1;i<=n;i++){
			max1=0;
			max2=0;
			max3=0;
			for(int j=1;j<=n;j++){
				if(a1[j]>max1){
					max1=a1[j];
					p1=j;
				}
			}
			for(int j=1;j<=n;j++){
				if(a2[j]>max2){
					max2=a2[j];
					p2=j;
				}
			}
			for(int j=1;j<=n;j++){
				if(a3[j]>max3){
					max3=a3[j];
					p3=j;
				}
			}
			if(max1>=max2&&max1>=max3){
				s=s+max1;
				n1++;
				a1[p1]=0;
				a2[p1]=0;
				a3[p1]=0;
			}else if(max2>=max1&&max2>=max3){
				s=s+max2;
				n2++;
				a1[p2]=0;
				a2[p2]=0;
				a3[p2]=0;
			}else if(max3>=max1&&max3>=max2){
				s=s+max3;
				n3++;
				a1[p3]=0;
				a2[p3]=0;
				a3[p3]=0;
			}
			if(n1>=n/2){
				for(int w=1;w<=n;w++){
					a1[w]=0;
				}
			}
			if(n2>=n/2){
				for(int w=1;w<=n;w++){
					a2[w]=0;
				}
			}
			if(n3>=n/2){
				for(int w=1;w<=n;w++){
					a3[w]=0;
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
