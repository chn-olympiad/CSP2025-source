#include<bits/stdc++.h>
using namespace std;
int n,m;
int data[111][111];
bool used[111][111];
int score[111];
int num;
int c=1;
int pos;
int myscore;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>myscore;
	score[1]=myscore;
	for(int i=2;i<=n*m;i++){
		cin>>score[i];
	}
	sort(score+1,score+n*m+1,cmp);
	for(int i=1; i<=n; i++) {
		if(i%2==0) {
			for(int j=m; j>=1; j--) {
				data[i][j]=c;
				c++;
			}
			continue;
		}
		for(int j=1; j<=m; j++) {
			data[i][j]=c;
			c++;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(score[i]==myscore){
			pos=i;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(data[i][j]==pos){
				cout<<i<<" "<<j<<" ";
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

