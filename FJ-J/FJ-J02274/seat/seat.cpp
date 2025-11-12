#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int score[110];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
		
	}int tmp=score[1];
	sort(score+1,score+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cnt++;
			if(score[cnt]==tmp){
				if(i%2==1){
					cout<<i<<' '<<j;
				}else{
					cout<<i<<' '<<n-j+1;
				}
			}
		}
	}
	
	return 0;
} 
