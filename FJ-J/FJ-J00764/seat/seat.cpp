#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,g[N][N];
bool st[N];
struct Node{
	int score;
	int x,y;
};
Node s[N];
bool cmp(Node a,Node b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>s[i].score;
	int a=s[1].score;
	sort(s+1,s+n*m+1,cmp);
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				g[i][j]=s[cnt].score;
				s[cnt].x=i,s[cnt].y=j;
				cnt++;
			}
		}	
		if(i%2==0){
			for(int j=m;j>=1;j--){
				g[i][j]=s[cnt].score;
				s[cnt].x=i,s[cnt].y=j;
				cnt++;
			}
		}	
	}
	cnt=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(s[cnt].score==a){
				cout<<s[cnt].x<<" "<<s[cnt].y;
				return 0;
			}
			cnt++;
		}
	return 0;
}
/*
			ʺ
			ʺ
			ʺ
ʺ			ʺ			ʺ
ʺ			ʺ			ʺ
ʺ			ʺ			ʺ
ʺ			ʺ			ʺ
ʺ			ʺ			ʺ
ʺ			ʺ			ʺ
ʺʺʺʺʺʺʺʺʺʺʺʺʺ
*/
