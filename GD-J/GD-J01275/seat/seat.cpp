#include <bits/stdc++.h>
using namespace std;

const int maxn=110;
int nums[maxn];
int n,m,lans,hans;

void open(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}
void input(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&nums[i]);
	}
}
bool cmp(int a,int b){return a>b;}
void solve(){
	int ir=nums[1];
	int sz=n*m;
	sort(nums+1,nums+sz+1,cmp);
	int k;
	for(int i=1;i<=n*m;i++){
		if(nums[i]==ir){
			k=i;break;
		}
	}
	lans=(k-1)/n+1,hans=(k-1)%n+1;
	if(lans%2==0){
		hans=n-hans+1;
	} 
}
void output(){
	printf("%d %d",lans,hans);
}
int main(){
	open();
	input();
	solve();
	output();
	close();
	return 0;
}
/*
Test
test-1 pass
test-2 pass
test-3 pass
*/

