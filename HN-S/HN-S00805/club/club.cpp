#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1e6+5;
int t,n,ans;
struct Node{
	int a,b,c;
}stu[maxn];
void dfs(int x,int n1,int n2,int n3,int sum){
	if(x>n){
		ans=max(ans,sum);
		return ;
	}
	if(n1<n/2){
		dfs(x+1,n1+1,n2,n3,sum+stu[x].a);
	}
	if(n2<n/2){
		dfs(x+1,n1,n2+1,n3,sum+stu[x].b);
	}
	if(n3<n/2){
		dfs(x+1,n1,n2,n3+1,sum+stu[x].c);
	}
}
bool cmp(Node x,Node y){
	return x.a>y.a;	
}
bool Cmp(Node x,Node y){
	return max(x.a,x.b)>max(y.a,y.b);
}
void solve(){
	cin>>n;
	ans=0;
	bool flag1=1,flag2=1;
	for(int i=1;i<=n;i++){
		cin>>stu[i].a>>stu[i].b>>stu[i].c;
		if(stu[i].b!=0||stu[i].c!=0){
			flag1=0;
		}
		if(stu[i].c!=0){
			flag2=0;
		}
	}
	if(flag1==1){
		sort(stu+1,stu+n+1,cmp);
		int sum=0;
		for(int i=1;i<=n/2;i++){
			sum+=stu[i].a;
		}
		cout<<sum<<endl;
	}
	else if(flag2==1){
		sort(stu+1,stu+n+1,Cmp);
		int sum=0,tmp1=0,tmp2=0;
		for(int i=1;i<=n;i++){
			if(stu[i].a>stu[i].b&&tmp1<n/2){
				tmp1++;
				sum+=stu[i].a;
			}
			else if(stu[i].a<stu[i].b&&tmp2<n/2){
				tmp2++;
				sum+=stu[i].b;
			}
			else{
				sum+=stu[i].a;
			}
		}
		cout<<sum<<endl;
	}
	else{
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
45pts
©³©©©©©©©©©©©©©©©· ©³©©©©©©©©©©©©©©©·          ©³©©©©©·                  ©³©©©©©·  
©«   ©³©©©©©·   ©« ©«   ©³©©©©©·   ©«          ©«    ©«                  ©«    ©«
©«   ©«    ©«   ©« ©«   ©«    ©«   ©«          ©«    ©«                  ©«    ©«
©«   ©»©©©©©¿   ©« ©«   ©»©©©©©¿   ©«  ©³©©©©©©©¿    ©»©©©©©©©·  ©³©©©©©©©¿    ©»©©©©©©©·
©«    ©²\    \©©©¿ ©«    ©²©©©©©©©©©¿  ©«                    ©«  ©«                    ©«
©«    ©« \    \    ©«    ©«            ©»©©©©©©©·    ©³©©©©©©©¿  ©»©©©©©©©·    ©³©©©©©©©¿
©«    ©«  \    \   ©«    ©«                    ©«    ©«                  ©«    ©«
©«    ©«   \    \  ©«    ©«                    ©«    ©«                  ©«    ©« 
©»©©©©©¿   ©»©©©©©¿©»©©©©©¿                    ©»©©©©©¿                  ©»©©©©©¿
*/
