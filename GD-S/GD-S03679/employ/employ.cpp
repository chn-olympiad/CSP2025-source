#include<bits/stdc++.h>
using namespace std;
int qp(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans*=a,ans%=998244353;
		a*=a;
		b>>=1;
	}
	return ans%998244353;
}
int n,m,a[114514],sum;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			sum++;
		}
	}
	cout<<qp(m,sum)%998244353;
	//学校推荐我去NOIP好不好.jpg 
	//┪┪我要当+ 
}
	
