#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,num,ct;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0,len=n*m;i<len;i++){
		scanf("%d",a+i);
		
	}
	num=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0,len=n*m;i<len;i++){
		if(a[i]==num){
			cnt=i+1;
		}
	}
	ct=cnt/n;
	cnt%=n;
	if(cnt==0){
		cnt=n;
		ct-=1;
	}
	printf("%d ",ct+1);
	if(ct&1){
		printf("%d",n-cnt+1);
	}else{
		printf("%d",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
