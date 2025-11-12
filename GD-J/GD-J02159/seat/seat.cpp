#include<bits/stdc++.h>
using namespace std;
const int N=111;
int score[N]; 
int seat[N][N];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
	}
	int pos=1;
	int mubiao=score[1];
	sort(score+1,score+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				seat[j][i]=score[pos];
				if(seat[j][i]==mubiao){
					cout<<i<<' '<<j;
					return 0;
				}
				pos++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				seat[j][i]=score[pos];
				if(seat[j][i]==mubiao){
					cout<<i<<' '<<j;
					return 0;
				}
				pos++;
			}
		}
	}
	return 0;
}

