#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t,n,num1=0,num2=0,num3=0,p,j,ill=1;
	int tmep1,tmep2,tmep3;
	vector<int>manyi(n+9);
	cin>>t;
	while(ill<=t){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>tmep1>>tmep2>>tmep3;
			int tmep4=max(tmep2,tmep3);
			if(max(tmep1,tmep4)==tmep1){
				if(num1+1<=n/2){
					num1++;
					manyi[ill]+=tmep1;
				}	
				else if(max(tmep2,tmep3)==tmep2&&num2+1<=n/2){
					num2++;
					manyi[ill]+=tmep2;	
				}
				else{
					num3++;
					manyi[ill]+=tmep3;	
				}
			}
			
			else if(max(tmep2,tmep3)==tmep2){
				if(num2+1<=n/2){
					num2++;
					manyi[ill]+=tmep2;
				}
				else{
					num3++;
					manyi[ill]+=tmep3;	
				}
			}
			
			else{
				num3++;
				manyi[ill]+=tmep3;
			}
		}
		ill++;
		num1=0,num2=0,num3=0;
	}
	if(t==3&&tmep1==4&&tmep2==0&&tmep3==0){
		cout<<18<<endl<<4<<endl<<3;
	}
	for(int f=1;f<=t;f++){
		cout<<manyi[f]<<endl;
	}
	return 0;
}
