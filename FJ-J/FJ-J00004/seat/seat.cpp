#include<bits/stdc++.h>
using namespace std;
int stu[114];
int solve(int b){
	int g=stu[1];
	sort(stu+1,stu+b+1);
	for(int i=1;i<=b;i++){
		if(stu[i]==g)return b-i+1;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int lie=1,hang=1,sign=1;
	int n,m,a;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>stu[i];
	a=solve(n*m);
	if(a==1){
		cout<<"1 1";
		return 0;
	}
	for(int i=1;i<=a-1;i++){
		if((hang==n&&sign==1)||(hang==1&&sign==-1)){
			lie++;
			sign*=-1;
			continue;
		}hang+=sign;
	}cout<<lie<<" "<<hang;
	return 0;
}