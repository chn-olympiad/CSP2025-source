#include <bits/stdc++.h>
using namespace std;
int n,m,score[110],seat[15][15],c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
	}
	int s_score=score[1];
	sort(score+1,score+1+n,cmp);
	int idex=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(score[idex]==s_score){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				if(score[idex]==s_score){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}
		idex+=1;
	}
	return 0;
}