#include<bits/stdc++.h>
 using namespace std;
 int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
int n,t,l=0,m=0,r=0,max=0,e=1;
int a[100005][3];
int w[100005];
cin>>n;
for(int i=1;i<=n;i++){
	cin>>t;
	for(int j=1;j<=t;j+=3){
	cin>>a[j][1]>>a[j][2]>>a[j][3];
	
for(int i=0;i<n;i++){
	e*=3;
}
for(int i=1;i<=e;i++){
	
	for(int j=1;j<=3;j++){
		if(l<=n/2&&m<=n/2&&r<=n/2){
				w[i]+=a[(i-j)/3][j];
		if(max<=w[i]){
			max=w[i];
		}
	}else{
		
		return 0;
	}
	}

}
cout<<max;
e=0; 
}
}



	 return 0;
 }
