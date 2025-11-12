#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int v;
	cin >> v;
	while(v>0){
	int add = 0;
	int aaa = -1;
	int lastaaa = -1;
	//cin
	int n;
	cin >> n;
	int j[3][n];
	int place[n];
	int place2[n];
	int num[n];
	int count[3]={0,0,0};
	for(int i=0;i<n;i++){
			for(int k=0;k<3;k++){
				cin >> j[k][i];
			}
		}
bool flag =1;
while(flag==1){
	for(int i=0;i<n;i++){
			int zuidazhi=-1,point=-1,point2=-1;
			for(int k=0;k<3;k++){
				if(j[0][i]==-1 or j[1][i]==-1 or j[2][i]==-1)break;
				if(zuidazhi < j[k][i]){
					zuidazhi = j[k][i];
					point = i;
					point2 = k;
				}
			}
			num[i]=zuidazhi;
			place[i]=point;
			place2[i]=point2;
		}
	for(int i=0;i<n;i++){
		cout << num[i] << " " << endl;}
	//paixv
	bool flag2 = 1;
	while(flag2==1){
		flag2=0;
	for(int i=0;i<n-1;i++){
		if(num[i]<num[i+1]){
				int c = num[i+1];
				num[i+1]= num[i];
				num[i] = c;
				c = place[i+1];
				place[i+1] = place[i];
				place[i]=c;
				c = place2[i+1];
				place2[i+1] = place2[i];
				place2[i]=c;
				flag2 = 1;
			}
		}
	}
	//jiafen
	flag=0;
	int i = 0;
	while(num[i]!=-1&&count[place2[i]]<n/2){
		count[place2[i]]++;
		add += num[i];
		j[place2[i]][place[i]]=-1;
		i++;
		aaa++;
		if(i==n){break;}
	}
	
	for(int i=0;i<n;i++){
		if(num[i]!=-1){
			flag=1;
			break;
		}
	}
		if(lastaaa==aaa){
			break;}
	lastaaa=aaa;

}		
		v--;
		cout << add;
	}
	return 0;
}
