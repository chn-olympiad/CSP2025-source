#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=998244353;
int n,m,s0,s1,ans,a[N],b[N],box[N];
bool vis[N];
string s;
void f(int step){
	if(step>n){
		int num1=0,num0=0;
		for(int i=1;i<=n;i++){
			int x=a[box[i]];
			if(num0>=x)num0++;
			else if(s[i-1]=='1')num1++;
			else{
				num0++;
			}
		}
		if(num1>=m)ans++;
		ans%=M;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			box[step]=i;
			f(step+1);
			vis[i]=0;
		}
	}
}
signed main(){
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')s0++;
		else s1++;
	}
	if(s1<m){
		cout<<"0";
		return 0;
	}
	if(s0==0){
		ll sum=1,cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=0)b[++cnt]=a[i];
		}
		for(int i=1;i<=cnt;i++){
			sum*=i;
			sum%=M;
		}
		cout<<sum;
	}
	else if(n<=10){
		f(1);
		cout<<ans;
	}
	return 0;
}//Ren5Jie4Di4Ling5%
