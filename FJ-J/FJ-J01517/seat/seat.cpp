#include<bits/stdc++.h>
using namespace std;
int n,m,seat[15][15];
struct students{
	int num;
	int exams;
}a[105];
bool cmpa(students a,students b){
	return a.exams>b.exams;
}
bool cmpb(students a,students b){
	return a.num<b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		a[i].num=i;
		cin>>a[i].exams;
	}
	sort(a+1,a+n*m+1,cmpa);
	//cout<<a[1].exams<<a[1].num<<a[3].exams<<a[3].num;
	for(int i=1;i<=n*m;i++)if(a[i].num==1){
		//cout<<a[i].num<<i;
		if(i%n==0){
			//cout<<1;
			if((i/n)&2==0)cout<<i/n<<' '<<1;
			else if((i/n)%2==1)cout<<i/n<<' '<<n;
		}
		else{//i=3
			//cout<<1;
			if((i/n+1)%2==0)cout<<i/n+1<<' '<<n-i%n+1;
			else if((i/n+1)%2==1)cout<<i/n+1<<' '<<i%n;
		}
		return 0;
	}
}
