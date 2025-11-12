#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
int n;
int a[5050];
int b[5050];//存在下表(0没走过)(1走过)(2定下来) 
int c[5050];//下表 
void fun(int u,int sum,int cnt,int mx){
//	cout<<u<<" "<<sum<<" "<<cnt<<" "<<mx<<endl;
	if(cnt>=3&&sum>mx*2&&mx!=-1){
		int flag=0; 
		for(int i=1;i<=cnt;i++){
//			cout<<c[i]<<" ";
			if(b[c[i]]==1){
				flag=1;
				break;
			}
		}
//		cout<<endl;
		if(flag==1){
			ans++;
			ans%=998244353;
			for(int i=1;i<=cnt;i++){
			b[c[i]]=2;
		}
	}
		
//		cout<<endl;
//		cout<<u<<" "<<sum<<" "<<cnt<<" "<<mx<<endl;
	}
	if(u>n){
		return ;
	}
	b[u]=1;
	cnt++;
	c[cnt]=u;
	sum+=a[u];
	fun(u+1,sum,cnt,a[u]);
	b[u]=0;
	c[cnt]=0;
	cnt--;
	sum-=a[u];
	fun(u+1,sum,cnt,mx);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	fun(1,0,0,-1);
	cout<<ans;
	return 0;
}
//5
//1 2 3 4 5
