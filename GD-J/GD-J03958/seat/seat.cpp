#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,p,c=1,r=1,ar=1;
int num[105];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>num[i];
	}
	p=num[1];
	sort(num+1,num+1+n*m,cmp);
	int i=1;
	while(1){
		if(num[i]==p){
			break;
		}
		if(i%n==0){
			c++;
			ar=-1;
		}else if(i%(n*2)==0){
			c++;
			ar=1;
		}else{
			r+=ar;
		}
		i++;
	}
	cout<<c<<' '<<r;
	return 0;
}



