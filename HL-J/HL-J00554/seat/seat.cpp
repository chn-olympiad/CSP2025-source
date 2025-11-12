#include<bits/stdc++.h>
using namespace std;

int score[110];

int v[2]={1,-1};

bool cmp(int x,int y){
	return x>y;
}

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> score[i];
	}
	int a=score[1];
	int s=0;
	sort(score+1,score+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(score[i]==a){
			s=i-1;
			break;
		}
	}
	int d=0;
	int x=1,y=1;
	while(s!=0){
		int dy=y+v[d];
		if(dy>n || dy<1){
			d++;
			d%=2;
			x+=1;
		}else{
			y=dy;
		}
		s--;
	}
	printf("%d %d",x,y);
	
	return 0;
}
