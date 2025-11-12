#include<bits/stdc++.h>
using namespace std;
int score[105],r,cnt=0,x=0,y=0;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=0;i<n*m;i++){
	cin>>score[i];
}
r=score[0];
sort(score,score+m*n);
for(int i=0;i<m*n/2;i++){
	swap(score[i],score[m*n-1-i]);
}
while(cnt<n*m){
	if(score[cnt]==r){
		cout<<y+1<<" "<<x+1;
		return 0;
	}
	cnt++;
	if(y%2==0 && x<n-1){
		x++;
		continue;
	}
	if(y%2==1 && x>0){
		x--;
		continue;
	}
	if(x==m-1 && y%2==0)y++;
	if(x==0 && y%2==1)y++;
}
	return 0;
}
