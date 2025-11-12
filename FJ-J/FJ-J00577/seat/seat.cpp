#include<bits/stdc++.h>
using namespace std;
int num[110];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	int n,m,R;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>num[i];
	}
	R=num[0];
	sort(num+0,num+(n*m),cmp);
	int index=0;
	for(int i=0;i<n*m;i++){
		if(num[i]==R){
			break;
		}
		index++;
	}
	int c=1,r=1,s=index/m,y=index%m;
	c=c+s;
	if(s%2==0){
		r=r+y;
	}else{
		r=m-y;
	}
	cout<<c<<" "<<r;
	return 0;
}
