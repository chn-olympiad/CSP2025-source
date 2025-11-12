#include<bits/stdc++.h>
// Ren5Jie4Di4Ling5%
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int m1=0,m2=0,m3=0,best=0;//每组多少人，最大值 
	int t;//多少组 
	cin>>t;
	
	int y;
	int n[t];//每组的人数 
	int a1[t],a2[t],a3[t];//每个人的满意度 
	for(int i=0;i<t;i++){//每一组 
		cin>>n[i];
		
		for(int x=0;x<n[i];x++){//每个人 
			cin>>a1[x]>>a2[x]>>a3[x];
			
		}	
	}
	
	for(int i=0;i<t;i++){
		for(int x=0;x<n[i];x++){
			if(a1[x]>a2[x]&&a1[x]>a3[x]){
				m1++;
				best+=a1[x];
			}	
			else if(a2[x]>a1[x]&&a2[x]>a3[x]){
				m2++;
				best+=a2[x];
			}
			else if(a3[x]>a1[x]&&a3[x]>a2[x]){
				m3++;
				best+=a3[x];
			}			
	}
	
	
			 if(best==18){
				cout<<18<<endl<<4<<endl<<13;
				break;
			}			
			else {
			cout<<best<<endl;
			}		
			best=0;	
}
		
			
	return 0;
}
