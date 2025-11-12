//GZ-S00485 贵阳市观山湖区外国语实验中学 陶昊冉 
#include<bits/stdc++.h>
using namespace std;
bool ping[2005]={0};
int tong1[2005],tong2[2005],tong3[2005];
int n,m,a,b,c,dan;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>m;
		for(int j = 0;j<m;j++){
			cin>>a>>b>>c;
			a = tong1[i];
			b = tong2[i];
			c = tong3[i];
		}
		for(int j = 2000;j>=0;j++){
			if(tong1[i]!=0&&ping[i]==0){
				dan += tong;
				ping[i] = 1;
			} 
			if(tong2[i]!=0&&ping[i]==0){
				dan += tong2;
				ping[i] = 1;
			}  
			if(tong3[i]!=0&&ping[i]==0){
				dan += tong3;
				ping[i] = 1;
			} 
		}
		cout<<dan;
	}
	return 0;
}

