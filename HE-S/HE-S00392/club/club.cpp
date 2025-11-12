#include<bits/stdc++.h>
using namespace std;

int a1[100001],a2[100001],a3[100001],bjmaxa[100001];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	for(int iii=1;iii<=t;iii++){
		int n;
		cin>>n;
		if(n==2){
			for(int j=1;j<=n;j++){
				cin>>a1[j]>>a2[j]>>a3[j];
			}
			int abcd=0;
			for(int j=1;j<=n;j++){
				if(a1[j]>a2[j]){
					if(a1[j]>a3[j]){
						abcd+=a1[j];
					}else{
						abcd+=a3[j];
					}
				}else{
					if(a3[j]>a2[j]){
						abcd+=a3[j];
					}else{
						abcd+=a2[j];
					}
				}
			}
			cout<<abcd<<endl;
		}
		else{
			for(int j=1;j<=n;j++){
				cin>>a1[j]>>a2[j]>>a3[j];
			}
			
			int xamax1=0,la1max=0,bjjla1;
			for(int k=1;k<=n/2;k++){
				la1max=0;
				for(int j=1;j<=n;j++){
					if(la1max<a1[j]&&bjmaxa[j]!=-1){
						la1max=a1[j];
						bjjla1=j;
					}
				}
				bjmaxa[bjjla1]=-1;
				xamax1+=la1max;
			}
			for(int k=1;k<=n;k++){
				if(bjmaxa[k]!=-1){
					if(a3[k]>a2[k]){
						xamax1+=a3[k];
					}else{
						xamax1+=a2[k];
					}
				}
			}
//			//得到了以评价一开头的最大值 
//			int xamax2=0,la2max=0,bjjla2;
//			for(int k=1;k<=n/2;k++){
//				la2max=0;
//				for(int j=1;j<=n;j++){
//					if(la2max<a1[j]&&bjmaxa[j]!=-1){
//						la2max=a1[j];
//						bjjla2=j;
//					}
//				}
//				bjmaxa[bjjla2]=-1;
//				xamax2+=la2max;
//			}
//			
//			for(int k=1;k<=n;k++){
//				if(bjmaxa[k]!=-1){
//					if(a3[k]>a1[k]){
//						xamax2+=a3[k];
//					}else{
//						xamax2+=a1[k];
//					}
//				}
//			}
//			//得到了以评价二开头的最大值 
			cout<<xamax1<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
}




			
//			int xamax3=0,la3max=0,bjjla3;
//			for(int k=1;k<=n/2;k++){
//				la3max=0;
//				for(int j=1;j<=n;j++){
//					if(la3max<a1[j]&&bjmaxa[j]!=-1){
//						la3max=a1[j];
//						bjjla3=j;
//					}
//				}
//				bjmaxa[bjjla3]=-1;
//				xamax3+=la3max;
//			}
//			
//			for(int k=1;k<=n;k++){
//				if(bjmaxa[k]!=-1){
//					if(a2[k]>a1[k]){
//						xamax3+=a2[k];
//					}else{
//						xamax3+=a1[k];
//					}
//				}
//			}
			//得到了以评价三开头的最大值 

//			int maxa123=max(xamax1,xamax2,xamax3);
//			int maxa123=max(xamax1,xamax2);
//			cout<<maxa123<<endl;
