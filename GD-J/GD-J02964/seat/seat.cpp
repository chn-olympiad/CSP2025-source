#include<bits/stdc++.h>
using namespace std;
bool bmp(int x,int y){
	return x>y;
}
int Stu123[100]={};
int NrD,MrD;
int XiaoRk=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>NrD>>MrD;
	for(int i=0;i<NrD*MrD;i++){
		cin>>Stu123[i];
	}
	XiaoRk=Stu123[0];
	sort(Stu123,Stu123+NrD*MrD,bmp);
	for(int i=0;i<NrD*MrD;i++){
		if(Stu123[i]==XiaoRk){
			int Line=(i+1)/NrD;
			double Line11=(i+1.0)/NrD;
			if(Line<Line11){
				Line++;
			}
			if(Line%2==0){
				cout<<Line<<" "<<NrD+1-(i+1-(Line-1)*NrD);
			}
			else{
				cout<<Line<<" "<<i+1-(Line-1)*NrD;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
