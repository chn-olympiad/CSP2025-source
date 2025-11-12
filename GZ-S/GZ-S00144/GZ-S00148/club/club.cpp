// GZ-S00148 贵阳雅礼高级中学（贵阳市第九中学） 张修涵 
#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen(club.in,"r",stdin);
	freopen(club.out,"w",stdout);
	cin>>n;
	for(int popi=1;popi<=n;popi++){
		int xuanyi[100005]={0} ,xuaner[10005]={0},xuansan[10005]={0},baoxiao=90000009,xuhao=0;
		int renshu=0,cnt=0,diyi[100005]={0},dier[100005]={0},disan[100005]={0},yi=0,er=0,san=0,tong12=0,tong13=0,tong123=0,tong23=0;
		cin>>renshu;
		for(int i=1;i<=renshu;i++){
			cin>>diyi[i]>>dier[i]>>disan[i];
			if(diyi[i]>max(dier[i],disan[i])){
				cnt+=diyi[i];
				yi++;
				xuanyi[i]=diyi[i];
			}else if(diyi[i]>disan[i] and diyi[i]==dier[i]){
				cnt+=diyi[i];
				tong12++;
				yi++;
			}		
			if(dier[i]>max(diyi[i],disan[i])){
				cnt+=dier[i];
				er++;
				xuaner[i]=dier[i];
			}else if(dier[i]>diyi[i] and disan[i]==dier[i]){
				cnt+=dier[i];
				tong23++;
				er++;
			}			
			if(disan[i]>max(diyi[i],dier[i])){
				cnt+=disan[i];
				san++;
				xuansan[i]=disan[i];
			}else if(disan[i]>dier[i] and disan[i]==diyi[i]){
				cnt+=diyi[i];
				tong13++;
				san++;
			}else if(disan[i]==dier[i] and dier[i]==diyi[i]){
				tong123++;
				cnt+=diyi[i];
				yi++;
			}
				
		}
		if(yi<=renshu/2 and er<=renshu/2 and san<=renshu/2){
			cout<<cnt<<endl;
		
		}else if(yi>renshu/2){
			
			if(tong123+tong12<yi-renshu/2){
				for(int j=1;j<=yi-tong123-tong12-renshu/2;j++)
					for(int i=1;i<=renshu;i++){
						if(xuanyi[i]<baoxiao and xuanyi[i]!=0){
							baoxiao=xuanyi[i];
							xuhao=i;
						}
					}
				cnt+=max(dier[xuhao],disan[xuhao]);
				cnt-=diyi[xuhao];
			}
			baoxiao=90000009,xuhao=0;
			cout<<cnt<<endl;
			
		}else if(er>renshu/2){

			if(tong23<er-renshu/2){
				for(int j=1;j<=er-tong23-renshu/2;j++){
					for(int i=1;i<=renshu;i++){
						
						if(xuaner[i]<baoxiao and xuaner[i]!=0){
							baoxiao=xuaner[i];
							xuhao=i;
							
						}
					}
				}
				cnt+=max(diyi[xuhao],disan[xuhao]);
				cnt-=dier[xuhao];
			}
			baoxiao=90000009,xuhao=0;
			cout<<cnt<<endl;
		}else if(san>renshu/2){
			if(tong13<san-renshu/2){
				for(int j=1;j<=san-tong13-renshu/2;j++)
					for(int i=1;i<=renshu;i++){
						if(xuansan[i]<baoxiao and xuansan[i]!=0){
							baoxiao=xuansan[i];
							xuhao=i;
						}
					}
				cnt+=max(dier[xuhao],diyi[xuhao]);
				cnt-=disan[xuhao];
			}
			baoxiao=90000009,xuhao=0;
			cout<<cnt<<endl;
		}
	}
	return 0;
}
