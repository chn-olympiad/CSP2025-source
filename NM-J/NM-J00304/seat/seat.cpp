#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,score[105]={},rpos,rscore;
	cin>>n>>m;
	int total=n*m;
	for(int i=1;i<=total;i++){
		cin>>score[i];
	}
	rscore=score[1];
	sort(score+1,score+total+1,cmp);
	for(int i=1;i<=total;i++){
		if(score[i]==rscore){
			rpos=i;
		}
	}
	if(!rpos%m){
		int rm=rpos/m;
		if(!rm%2){
			cout<<1<<" "<<rm;
		}
		else{
			cout<<n<<" "<<rm;
		}
	}
	else{
		int rm=rpos/m+1;
		if(!rm%2){
			cout<<rpos%m<<" "<<rm;
		}
		else{
			cout<<n-(rpos%m)+1<<" "<<rm;
		}
	}
	return 0;
}
