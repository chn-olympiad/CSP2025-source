#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[10005],cnt,ans,tmp;
bool flag=0;
struct node{
	int wh1,f,wh2;
}e[100005];
bool cmp(node a,node b){
	return a.f>b.f;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>e[i].f;
		e[i].wh1=i;
	}
	sort(e+1,e+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(e[i].wh1==1){
			cnt=i;	
			break;
		} 
	}
	if(cnt%n==1) tmp=cnt/n+1;
	else tmp=cnt/n;
	if(tmp%2==1&&cnt%n!=0&&!flag){
		ans=cnt%n;
		flag=1;
	}
	else if(tmp%2==0&&cnt%n==1&&!flag){
		ans=n;
		flag=1;
	}
	else if(tmp%2==1&&cnt%n==1&&!flag){
		ans=1;
		flag=1;
	}
	else if(tmp%2==0&&cnt%n!=0&&!flag){
		ans=n-cnt%n;
		flag=1;
	}
	else if(tmp%2==1&&cnt%n==0&&!flag){
		ans=cnt;
		flag=1;
	}
	else ans=n-cnt%n;
	cout<<tmp<<" "<<ans;
	return 0;
} 
