#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5010];
struct node{
	string s;
};
int cs=0;
node b[2500010];
void dfs(string s1,int k,int j,long long sum,long long ma){
	sum=sum+a[j];
	s1+=j+'0';
	if(ma<a[j]) ma=a[j];
	if(sum>ma*2&&s1.size()==k){
		bool flag=true;
		for(int i=1;i<=cs;i++){
			if(s1==b[i].s){
				flag=false;
				break;
			}
		}
		if(flag==true){
			cs++;
			b[cs].s=s1;
		}
		return;
	}
	for(int i=j+1;i<=n;i++){
		dfs(s1,k,i,sum,ma);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			dfs("",i,j,0,a[j]);
//			cout<<i<<" "<<j<<" "<<cs%998244353<<endl;
		}
	}
	cout<<cs%998244353;
}
