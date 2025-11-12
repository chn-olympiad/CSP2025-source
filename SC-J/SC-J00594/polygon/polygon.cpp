#include<bits/stdc++.h>
#define _33550336_ 998244353
using namespace std;
int n;
int a[5010];
long long ans;
bool vis[5010];
int num,qu=0;
void dfs(int i){
	for(int j=i;j<=n;j++){
		if(vis[j])continue;
		if(ans>=_33550336_)ans%=_33550336_;
		num+=a[j],qu++;
		if(num>a[j]*2&&qu>=3){
			ans++;
		}
		vis[j]=true;
		dfs(j+1);
		num-=a[j],qu--;
		vis[j]=false;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2)cout<<1;
		else cout<<2;
		return 0;
	}
	if(a[n]==1){
		for(int j=0;j<=n;j++){
			for(int i=1;i+j<=n;i++){
				ans+=(n-i-j)*(n-i-j-1)/2;
				if(ans>=_33550336_)ans%=_33550336_;
			}
		}	
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
}
/* 
《Fly,My Wings》
Fly,broken wings,
I know you are still with me.
All I need is a nedge to get me started.
Fly,broken wings,
to somewhere I can be free.
Closer to our "IDEAL"

Teary eyed,
once gentle sour,
you see as me getting away.
The mirrow says,
that I still remember hope.
Emmmmmmm

You are doing what you love,
isn't that enough,isn't that enough?
A general(?),perfect job,
isn't that enough,isn't that enough?
Again and again,
you lock me down,I lock me down,we stack it to the ground.

The soil gave me warmth.

Please die ,little deams,
kill the camilias indeed(?).
Wouldn't it be easier to give in?
【E.G.O展现——乌瞰刀】 
Why are these hands chasing dreams out of my reach?
【你为理想作何定义】
Is me thirsty for normally "ODD"(?).
...

FLY,PERFECT WINGS,
WHERE HAVE YOU BEEN HIDING?
(GOODBYE,GOODBYE)
BRING ME TO THE MIND THAT GOT US STARTED.
FLR,PERFECT WINGS,
SHOW THEM WHO I CAN BE.
FOR THE ONE LAST TIME IF YOU WILL.

That's all.
*/

//你谷ID忘了如果入选我在评论区发留言qwq 