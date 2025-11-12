#include<bits/stdc++.h>
using namespace std;
int n,m;
struct seat{
	int soccer;
	int lend;
}stu[105];
bool cmp(const seat & x,const seat& y){
	return x.soccer>y.soccer;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>stu[i].soccer;
		stu[i].lend=i;
	}
	sort(stu+1,stu+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				cnt++;
				if(stu[cnt].lend==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=1;j<=m;j++){
				cnt++;
				if(stu[cnt].lend==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}