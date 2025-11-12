#include<bits/stdc++.h>
using namespace std;

int a[114][114], n, m, score[1145141], cnt, aim, nn=1, mm=0;

bool cmp(int a, int b){
	return a>b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=cnt;i++) cin>>score[i];
	aim=score[1];
	sort(score+1, score+1+cnt, cmp);
	
	int i=1;
	bool sign=1;
	while(1){
		if(sign){
			if(mm+1<=m) mm++;
			else sign=0, nn++;
		}
		else{
			if(mm-1>=1) mm--;
			else sign=1, nn++;
		}
		if(aim==score[i]) break;
		i++;
	}
	cout<<nn<<" "<<mm<<endl;
	return 0;
}