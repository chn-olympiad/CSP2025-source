#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int n;
cin>>n;
for(int i=0;i<n;i++){
	int m;
	cin>>m;
	if(m==2){
       int a[3];
       int b[3];
       cin>>a[0]>>a[1]>>a[2];
       cin>>b[0]>>b[1]>>b[2];
       int a1=0;
     if(a[0]>=a[1]&&a[0]>=a[2]){
    a1=1;
	 }else if(a[1]>=a[0]&&a[1]>=a[2]){
	 	a1=2;
	 }else{
	 	a1=3;
	 }
	       int b1=0;
     if(b[0]>=b[1]&&b[0]>=b[2]){
    b1=1;
	 }else if(b[1]>=b[0]&&b[1]>=b[2]){
	 	b1=2;
	 }else{
	 	b1=3;
	 }
	 sort(a,a+3);
	 sort(b,b+3);
		if(b1!=a1){
			cout<<a[2]+b[2]; 
		}else{
		int sum1=b[2]+a[1],sum2=b[1]+a[2];
				if(sum1>sum2){
					cout<<b[2]+a[1];
				}else{
					cout<<b[1]+a[2];
				}
		}
	}eles{
	int a[m][3];
	int nut=0;
	for(int j=0;j<m;j++){
		 cin>>a[j][0]>>a[j][1]>>a[j][2];
		 if(a[j][0]>=a[j][1]&&a[j][0]>=a[j][2]){
    nut+=a[j][0];
	 }else if(a[j][1]>=a[j][0]&&a[j][1]>=a[j][2]){
	nut+=a[j][1];
	 }else{
    nut+=a[j][2];
	 }
	}
	cout<<nut;
}
cout<<endl;
}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
