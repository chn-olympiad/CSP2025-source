#include<bits/stdc++.h>
using namespace std;
int n,m,a,s[105],cnt;
bool cmd(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	s[0]=a;
	for(int i=1;i<n*m;i++){
		scanf("%d",&s[i]);
	}
	sort(s,s+n*m,cmd);
	for(int i=0;i<n*m;i++){
		if(s[i]==a){
			cnt=i+1;
			break;
		}
	}
	if(cnt%n==0){
		if((cnt/n)%2==0){
			printf("%d %d",cnt/n,1);
		}else{
			printf("%d %d",cnt/n,n);
		}
	}else{
		if((cnt/n+1)%2==0){
			printf("%d %d",cnt/n+1,n-cnt%n+1);
		}else{
			printf("%d %d",cnt/n+1,cnt%n);
		}
	}
	return 0;
}