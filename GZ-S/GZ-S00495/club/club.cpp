//GZ-S00495 北京师范大学贵阳附属中学 饶周思源
#include<bits/stdc++.h>
using namespace std;
int a1[99999]={0},a2[99999]={0},a3[99999]={0};
int p1,p2,p3;
void locate(int n,int i){
	if(n==a1[i])	p1++;
	if(n==a2[i])	p2++;
	if(n==a3[i])	p3++;
}
int main(){
	
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int n;
	int t;
	cin>>t;
	
	int res;
	for(int i=1;i<=t;i++){
		res = 0 ;
		cin>>n;
		int rct=n/2;
		for(int j=1;j<=n;j++){//个人 
			
			cin>>a1[j]>>a2[j]>>a3[j];//分别为对三个部门的满意度 
			int ma1;//找出单个部门满意度最高的人 
			ma1=max(a1[j],a2[j]);
			ma1=max(ma1,a3[j]);
			locate(ma1,j);
			res+=ma1;
			if(p1>rct||p2>rct||p3>rct){
				int ma2;
				ma2=min(a1[j],a2[j]);
				ma2=min(ma2,a3[j]);
				if(a1[j]!=ma2&&a1[j]!=ma1){
					res-=ma1;
					ma1=a1[j];
					res+=ma1;
					
				}
				if(a2[j]!=ma2&&a2[j]!=ma1){
					res-=ma1;
					ma1=a2[j];
					res+=ma1;
					
				}
				if(a3[j]!=ma2&&a3[j]!=ma1){
					res-=ma1;
					ma1=a3[j];
					res+=ma1;
					
				}
			}
			
			
			
			
			
			cout<<res<<endl;
			
			
			
			
		}
		
	
	}
	
}
	

