#include<iostream>
using namespace std;
int t,n,ans;
char a1[3];
char a2[3];
char a3[3];
char a4[3];
int main(){
	cin>>t>>n;
	cin>>a1>>a2>>a3>>a4;
	for(int i=0;i<=2;i++){
		int temp1=a1[i];
		for(int m=0;m<=2;m++){
			int temp2=a2[m];
			for(int j=0;j<=2;j++){
				int temp3=a3[j];
				int num=temp1+temp2+temp3;
				if(num>ans){
					ans=num;
					num=0;
				}
				else
					num=0;
				
				
			}
		}
	}
	cout<<ans;
}
