#include<bits/stdc++.h>
using namespace std;
int n,m,s,R,c=0,r=0,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	int score[s+1];
	int s2[n+1][m+1];
	for(int i=1;i<=s;i++){
		cin>>score[i];
	}
	R=score[1];
	sort(score+1,score+s+1);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(i%2==1){
				s2[i][j]=score[num];
			}else{
				s2[i][j]=score[num];
				swap(s2[i][j],s2[i][j]);
			}
			if(s2[i][j]==R){
				c=i;
				r=j;	
			}
			num++;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
