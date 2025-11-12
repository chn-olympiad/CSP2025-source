//Forza Ferrari!
#include<iostream>
#include<algorithm>
using namespace std;
// long long score[114];
struct s{
	int x,y;//x hang y lie
	long long score;
};
s a[114];
bool cmp(s s1,s s2){
	return s1.score>s2.score;
}
int n,m;//hang n lie m
long long target;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%lld",&a[i].score);
	target=a[1].score;
	sort(a+1,a+1+n*m,cmp);
	// int c=1;
	int sx=1,sy=1;//x lie y hang
	bool first=1;
	bool f=0;//f=0 for downs f=1 for ups
	for(int i=1;i<=n*m;i++){
		if(sy==n+1||sy==0){
			sx++;//jia yi lie
			if(sx%2==0){
				sy=n;f=1;
			}
			else if(sx%2==1){
				sy=1;f=0;
			}
		}
		first=0;
		if(f){//dang xiangshangzou
			a[i].x=sy;//hangshujian1
			a[i].y=sx;//lieshububian
			sy--;
		}
		else if(!f){//dang xiangxiazou
			a[i].x=sy;//hangshujia1
			a[i].y=sx;
			sy++;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].score==target){
			printf("%d %d",a[i].y,a[i].x);
		}
	}
	return 0;
}