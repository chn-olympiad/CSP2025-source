#include<bits/stdc++.h>
using namespace std;
int n,m,me,mine;
int score[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>score[1];
	me=score[1];
	for(int i=2;i<=n*m;i++){
		cin>>score[i];
	}
	sort(score+1,score+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(score[i]==me){
			mine=i;
			break;
		} 
	}
	if(((mine-1)/n+1)%2==0) cout<<(mine-1)/n+1<<" "<<n-(mine-n*((mine-1)/n))+1;
	else cout<<(mine-1)/n+1<<" "<<(mine-1)%n+1;
	return 0;
}
