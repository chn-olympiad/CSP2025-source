#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][4],c[100001][4],p[10001],x[100001][4],m=0,sum=0,v=0,d=0;
int pt(){
	for(int i=1;i<=n;i++){
		for(int l=1;l<=3;l++){
		for(int j=1;j<=2;j++){
			   if(c[i][j]<=c[i][j+1]){
			   	   swap(c[i][j],c[i][j+1]);
			  }
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			v=m;
			if(m<=c[i][j]){
				m=c[i][j];
					p[j]++;
					d=j;
			}
        }
        if(p[d]<=n/2){
          sum=sum+m;
        }else{
        	sum=sum+v;
		}
  }
  return sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=3;l++){
				cin>>a[j][l];
				c[j][l]=a[j][l];
				x[j][l]=l;
			}
		
		}
		cout<<pt()<<endl;
	}
	return 0;
}
