#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
//列=si/n+1 
//行：若所在列为奇数，si%n+1   若所在列为偶数，5-(s1%n+1) 
//i从0开始 
struct stu{
	int scr,id;
}seat[N*N];
int n,m;
bool cmp(stu a,stu b){
	return a.scr>b.scr;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>seat[i].scr;
		seat[i].id=i;
	}sort(seat,seat+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(seat[i].id==0){
			int ans1=i/n+1,ans2;
			if(ans1%2==1)ans2=i%n+1;
			else ans2=(n+1)-(i%n+1);
			cout<<ans1<<' '<<ans2;
			return 0;
		}
	}
	return 0;
}
