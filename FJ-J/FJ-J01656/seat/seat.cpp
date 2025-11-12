#include<bits/stdc++.h>
using namespace std;
int n,m;

struct stu{
	int s;
	int num;
}stus[105];

bool cmp(stu a,stu b){
	return a.s>b.s;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>stus[i].s;
		stus[i].num=i;
	}
	sort(stus+1,stus+1+n*m,cmp);
	int r;
	for(int i=1;i<=n*m;i++){
		if(stus[i].num==1){
			r=i;
			break;
		}
	}
	int l=1,h=0;
	while(r>n){
		r-=n;
		l++;
	}
	if(l%2==1){
		h=r;
	}else{
		h=n-r+1;
	}
	cout<<l<<" "<<h;
	
	return 0;
}
