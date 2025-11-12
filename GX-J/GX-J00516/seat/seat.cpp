#include <bits/stdc++.h>
using namespace std;
struct student{
	int score;
	bool zj;
}stu[105],stu2[11][11];
bool cmp(student x,student y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>n >>m;
	for(int i=1;i<=n*m;i++){
		cin >>stu[i].score;
		stu[i].zj=0;
	}
	stu[1].zj=1;
	sort(stu+1,stu+n*m+1,cmp);
	int i=1,j=1,rd=1;
	while(rd<=n*m){
		stu2[i][j]=stu[rd];
		if(stu2[i][j].zj){
			cout <<j <<' ' <<i;
			return 0;
		}
		if(j%2==1){
			if(i==n) j++;
			else i++;
		}else{
			if(i==1) j++;
			else i--;
		}
		rd++;
	}
	return 0;
}
