#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,rscore;
	int rh=1,rl=1;
	int score[105]={0};
	cin>>n>>m;
	bool way=true;
	for(int i=0;i<n*m;i++){
		cin>>score[i];
	}
	rscore=score[0];
	sort(score,score+105,cmp);
	for(int i=0;i<n*m;i++){
		if(score[i]==rscore) break;
		else if(rh==n || rh==0){
			rl++;
			way=!way;
		}
		else if(way=true){
			rh++;
		}
		else{
			rh--;
		}
	}
	cout<<rl<<' '<<rh;
} 
