#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	char ch=getchar();
	ll x=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
} 
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
ll n,t; 
struct node1{
	ll s1,s2,s3;
};
struct node2{
	ll i,s;
};
ll sum1,sum2,sum3,ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		node1 a[100050];
		node2 q1[100050],q2[100050],q3[100050];
		priority_queue<ll>q;
		sum1=0,sum2=0,sum3=0,ans=0;
		cin>>n;
		for(ll i=1;i<=n;++i){
			a[i].s1=read();
			a[i].s2=read();
			a[i].s3=read();
		}
		for(ll i=1;i<=n;++i){
			if(a[i].s1>=a[i].s2&&a[i].s1>=a[i].s3) ans+=a[i].s1,q1[++sum1]=(node2){i,a[i].s1};
			else if(a[i].s2>=a[i].s1&&a[i].s2>=a[i].s3) ans+=a[i].s2,q2[++sum2]=(node2){i,a[i].s2};
			else ans+=a[i].s3,q3[++sum3]=(node2){i,a[i].s3};
		}
		if(sum1>n/2){
			for(ll i=1;i<=sum1;++i){
				ll ii=q1[i].i;
				q.push(max(a[ii].s2-a[ii].s1,a[ii].s3-a[ii].s1));
			}
			while(sum1>n/2){
				ans+=q.top();
				sum1--;
				q.pop();
			} 
		}
		else if(sum2>n/2){
			for(ll i=1;i<=sum2;++i){
				ll ii=q2[i].i;
				q.push(max(a[ii].s1-a[ii].s2,a[ii].s3-a[ii].s2));
			}
			while(sum2>n/2){
				ans+=q.top();
				sum2--;
				q.pop();
			} 
		} 
		else if(sum3>n/2){
			for(ll i=1;i<=sum3;++i){
				ll ii=q3[i].i;
				q.push(max(a[ii].s2-a[ii].s3,a[ii].s1-a[ii].s3));
			}
			while(sum3>n/2){
				ans+=q.top();
				sum3--;
				q.pop();
			} 
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
/*
黑塔女士举世无双
黑塔女士才华横溢
黑塔女士沉鱼落雁
黑塔女士冠绝寰宇
黑塔女士聪明绝顶
黑塔女士貌美如花
黑塔女士天下独绝
黑塔女士闭月羞花 
*/ 
