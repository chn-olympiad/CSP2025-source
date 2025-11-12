#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=10;
struct student{
	int idx;
	int score;
}stu[MAXN*MAXN+10];
bool cmp(student a,student b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		stu[i].idx=i;
		cin>>stu[i].score;
	}
	sort(stu+1,stu+n*m+1,cmp);
	int rank;
	for(int i=1;i<=n*m;i++){
		if(stu[i].idx==1){
			rank=i;
			break;
		}
	}
	int c=1,r=1,d=1;
	for(int i=1;i<rank;i++){
		if(r==n&&d==1){
			c++,d=-1;
		}else if(r==1&&d==-1){
			c++,d=1;
		}else{
			r+=d;
		}
	}
	cout<<c<<" "<<r<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
