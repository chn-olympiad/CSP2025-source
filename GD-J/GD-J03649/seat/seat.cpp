#include<bits/stdc++.h>
using namespace std;

int seat[20][20];
int s[200];
int peo;
priority_queue<int>q;
int num=1,now_m=1;
int n,m;


void solve2(){
	while(num){
		seat[num][now_m]=q.top();
		q.pop();
		num--;
	}
}

void solve1(){
	while(num<=n){
		seat[num][now_m]=q.top();
		q.pop();
		num++;
	}
	
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	peo=n*m;
	for(int i=1;i<=peo;i++){
		cin>>s[i];
		q.push(s[i]);
	}
	while(!q.empty()){
		if(now_m>m) break;
		num=1;
		solve1();
		now_m++;
		if(now_m>m) break;
		num=n;
		solve2();
		now_m++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==s[1]){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}

