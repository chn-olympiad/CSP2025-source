#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct s{
	int id;
	int score;
};

bool cmp(s a,s b){
	return a.score>b.score;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	s arr[105];
	int M,N;
	cin >> M >> N;
	for(int i=0;i<M*N;i++){
		int temp;
		cin >> temp;
		arr[i].score=temp;
		arr[i].id=i;
	}
	
	sort(arr,arr+M*N,cmp);
	
	int position;
	
	for(int i=0;i<M*N;i++){
		if(arr[i].id==0){
			position=i;
		}
	}
	
	int xp=position/M;
	int yp;
	if(xp%2==0){
		yp=position%M;
	} else{
		yp=M-position%M-1;
	}
	
	cout << xp+1 << ' ' << yp+1;
	
	return 0;
}
