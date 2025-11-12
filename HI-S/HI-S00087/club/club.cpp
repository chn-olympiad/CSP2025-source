#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int y,f;
}d[100005];
bool cmp(node x,node y){
	return x.y<y.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&t);
	while(t--){
		int cnt[5]={},sum=0;
		scanf("%d",&n);
		for(int i=1,a,b,c;i<=n;i++){
		    scanf("%d%d%d",&a,&b,&c);
		    int x=max(a,max(b,c));
			sum+=x;
		    if(x==a)d[i].y=a-max(b,c),cnt[1]++,d[i].f=1;
			if(x==b)d[i].y=b-max(a,c),cnt[2]++,d[i].f=2;
			if(x==c)d[i].y=c-max(b,a),cnt[3]++,d[i].f=3;
	    }
	    sort(d+1,d+n+1,cmp);
	    int i=1;
	    while(cnt[1]>n/2){
	    	if(d[i].f==1)sum-=d[i].y,cnt[1]--;
	    	i++;
	    }
	    while(cnt[2]>n/2){
	    	if(d[i].f==2)sum-=d[i].y,cnt[2]--;
	    	i++;
	    }
	    while(cnt[3]>n/2){
	    	if(d[i].f==3)sum-=d[i].y,cnt[3]--;
	    	i++;
	    }
	    printf("%d\n",sum);
	}
	return 0;
}
