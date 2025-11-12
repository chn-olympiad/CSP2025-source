#include<bits/stdc++.h>
using namespace std;

struct st{
	int sc;
	bool is1=0;
}stu[110];

bool cmp(st a,st b){
	return a.sc>b.sc;
}

int n,m;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>stu[i].sc;
		if(!i) stu[i].is1=1;
	}
	sort(stu,stu+n*m,cmp);
	
	int R=0;
	while(!stu[R].is1) R++;
	cout<<R/n+1<<" ";
	if(R/n%2==0){
		cout<<R%n+1;
	}else{
		cout<<n-R%n;
	}
	return 0;
}
