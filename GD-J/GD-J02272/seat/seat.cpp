#include<bits/stdc++.h> 
using namespace std;
int n,m;
int score[105];
int sum;
int col,line;
int R;
int index;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	sum=n*m;
	for(int i=1;i<=sum;i++){
		scanf("%d",&score[i]);
	}
	R=score[1];
	sort(score+1,score+sum+1,greater<int>());
	for(int i=1;i<=sum;i++){
		if(score[i]==R) index=i; 
	}
	if(index%n==0){
		col=index/n;
		if(col%2==1) line=n;
		else line=1;
	} 
	else{
		col=index/n+1;
		if(col%2==1) line=index%n; 
		else line=n-index%n+1;
	} 
	printf("%d %d",col,line);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
