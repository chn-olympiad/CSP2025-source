#include<bits/stdc++.h>
using namespace std;
struct stu{
	int score;
	int num;
};
int cmp(stu a,stu b){
	return a.score > b.score ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,klk;
	cin>>n>>m;
	stu a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i].score;
		a[i].num = i;
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i].num == 0){
			klk = ceil((double)(i+1)/m);
			cout<<klk<<" ";
			if(klk%2){
				cout<<i+1 - (m*(klk-1)+1) +1;
			}
			else{
				cout<<(m*klk)-(i+1) +1;
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
