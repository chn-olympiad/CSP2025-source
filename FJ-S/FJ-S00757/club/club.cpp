#include<bits/stdc++.h>
using namespace std;
int t,n,a1,a2,a3,a,b[3],c;
int main(){
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	cin>>t;
	for(int q=1;q<=t;q++){
		cin>>n;
		a1=0;
		a2=0;
		a3=0;
		a=0;
		if(n==2){
			cin>>a1>>a2>>a3>>b[0]>>b[1]>>b[2];
			if(b[0]==b[1]&&b[1]==b[2]){
				cout<<max(a1,max(a2,a3))+b[0]<<"\n";
				continue;
			}else if(b[0]==b[1]||b[0]==b[2]){
				cout<<max(a1,max(a2,a3))+b[0]<<"\n";
				continue;
			}else if(b[1]==b[2]){
				cout<<max(a1,max(a2,a3))+b[1]<<"\n";
				continue;
			}else{
				if(a1!=max(a1,max(a2,a3))&&a1!=min(a1,min(a2,a3))){
					a=a1;
				}else if(a2!=max(a1,max(a2,a3))&&a2!=min(a1,min(a2,a3))){
					a=a2;
				}else{
					a=a3;
				}
				if(b[0]!=max(b[0],max(b[1],b[2]))&&b[0]!=min(b[0],min(b[1],b[2]))){
					c=b[0];
				}else if(b[1]!=max(b[0],max(b[1],b[2]))&&b[1]!=min(b[0],min(b[1],b[2]))){
					c=b[1];
				}else{
					c=b[2];
				}
				cout<<max(max(a1,max(a2,a3))+c,max(b[0],max(b[1],b[2]))+a);
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>b[0]>>b[1]>>b[2];
			if(b[0]==b[1]&&b[1]==b[2]){
				if(a1<=a2&&a1<=a3){
					a1++;
					a+=b[0];
				}else if(a2<=a1&&a2<=a3){
					a2++;
					a+=b[1];
				}else{
					a3++;
					a+=b[2];
				}
			}else if(b[0]==b[1]){
				if(a1<=a2){
					a1++;
					a+=b[0];
				}else{
					a2++;
					a+=b[1];
				}
			}else if(b[0]==b[2]){
				if(a1<=a3){
					a1++;
					a+=b[0];
				}else{
					a3++;
					a+=b[2];
				}
			}else if(b[1]==b[2]){
				if(a2<=a3){
					a2++;
					a+=b[1];
				}else{
					a3++;
					a+=b[2];
				}
			}else{
				if(b[0]>b[1]&&b[0]<b[2]){
					a+=b[0];
					a1++;
				}else if(b[1]>b[0]&&b[1]<b[2]){
					a+=b[1];
					a2++;
				}else{
					a+=b[2];
					a3++;
				}
			}
		}
		cout<<a<<"\n";
	}
	return 0;
}
