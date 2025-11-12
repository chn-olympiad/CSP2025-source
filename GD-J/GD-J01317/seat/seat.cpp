#include <bits/stdc++.h>
using namespace std;
int n=1,m=1,score[1034],r=0,ans_h=0,ans_l=0,pos=0;
int main(){
	score[1]=7834;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&score[i]);
	}
	r = score[1];
	//printf("%d\n",r);
	sort(score+1,score+n*m+1);
	reverse(score+1,score+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(score[i]==r){
			pos=i;
			break;
		}
	}
	//printf("%d\n",pos);
	if(pos%n) ans_l=pos/n+1;
	else ans_l=pos/n;
	if(ans_l % 2 == 0){
		if(pos%n) ans_h=(n-pos%n)+1;
		else ans_h = 1;
	}else{
		if(pos%n) ans_h=pos%n;
		else ans_h = n;
	}
	printf("%d %d",ans_l,ans_h);
	return 0;
	//老师你英俊潇洒帅气大方，放我过吧 
	//3221225620
}
