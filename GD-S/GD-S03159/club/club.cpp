#include<bits/stdc++.h>
using namespace std;
int s,n,a[100001],b[100001],c[100001],a1=0,b1=0,c1=0,aj,bj,cj;
int max1=-1,max2=-1,max3=-1;
int main(){
	//freopen("club,in",r,stdin);
	//freopen("club,out",w,stdout);
	cin>>s;
	for(int m=1;m<=s;m++){
		cin>>n;
		a1=0,b1=0,c1=0;
		int k=0,max=-1;
		for(int i=1;i<=n;i++){
			max1=-1,max2=-1,max3=-1;
			cin>>a[i]>>b[i]>>c[i];
		}
		while(k<n){
			for(int i=1;i<=n;i++){
			 if(a[i]>max1&&a1<=(n/2)){
				max1=a[i];
				aj=i;
			}if(b[i]>max2&&b1<=(n/2)){
				max2=b[i];
				bj=i;
			}if(c[i]>max3&&c1<=(n/2)){
				max3=c[i];
				cj=i;
			}
			if(max1>=max2&&max1>=max3){
				max=max+max1;
				a[aj]=-1;
				b[aj]=-1;
				c[aj]=-1;
				k=k+1;
				a1=a1+1;
			}else if(max2>max1&&max2>=max3){
				max=max+max2;
				b[bj]=-1;
				a[bj]=-1;
				c[bj]=-1;
				k=k+1;
				b1=b1+1;
			}else {
				max=max+max3;
				c[cj]=-1;
				b[cj]=-1;
				a[cj]=-1;
				c1=c1+1;
				k=k+1;
			}
			max1=-1,max2=-1,max3=-1;
		}
	}
	cout<<max<<endl; 
		}
	return 0;
}









































//×Ü³¤¶È1145 
