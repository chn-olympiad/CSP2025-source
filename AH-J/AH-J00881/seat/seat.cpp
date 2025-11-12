#include<bits/stdc++.h>
using namespace std;
struct node{
	int score;
	int row,col;
}A[150];
bool cmp(node a,node b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N*M;i++)
		cin>>A[i].score;
	int R=A[1].score;
	sort(A+1,A+1+N*M,cmp);
	int i=1,j=1,pos=1;
	while(i*j<=N*M&&i<=N&&i>=0&&j>=0&&j<=M&&pos<=N*M){
		A[pos].row=j,A[pos].col=i;
		pos++;
		if(j%2==1) i++;
		else i--;
		if(i==N||(i==1&&j%2==0)){
			A[pos].row=j,A[pos].col=i;
			pos++;
			j++;
		}
	}
	for(int i=1;i<=N*M;i++){
		if(A[i].score==R){
			cout<<A[i].row<<" "<<A[i].col;
			return 0;
		}
	}
}
