#include<bits/stdc++.h>
using namespace std;
struct student{
	int score;
	int paiming;
	bool is_R;
}a[100];
int n,m;
int nR,mR;
int Rseat;
bool cmp1(student a,student b){
	return a.score>=b.score;
}
bool cmp2(student a,student b){
	return a.is_R>=b.is_R;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i].score;
		a[i].is_R=0;
	}
	a[1].is_R=1;
	sort(a+1,a+n*m+1,cmp1);
	for(int i=1;i<=n*m;++i){
		a[i].paiming=i;
	}
	sort(a+1,a+n*m+1,cmp2);
	Rseat=a[1].paiming;
	mR=(Rseat-1)/n + 1;
	nR=(Rseat-1)%m + 1;
	if(mR%2==0) nR=n+1-nR;
	cout<<mR<<' '<<nR<<'\n';
	return 0;
}
