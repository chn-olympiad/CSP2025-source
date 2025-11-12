#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e2+5,mod=998244353;

int n,m;
char dif[N];
int c[N];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>dif+1;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	
	int cnt1=0;
	for(int i=1;i<=n;i++)
		cnt1+=dif[i]-'0';
	
	int res=0;
	if(cnt1==n)
	{
		sort(c+1,c+1+n,cmp);
		
		int cnt2=0;
		res=1;
		for(int i=n-cnt2;i>1;i--)
			res=((ll)res*i)%mod;
		
		for(int i=1;i<=cnt2;i++)
			res=((ll)res*i)%mod;
		
	}//A
	
	cout<<res<<endl;
	
	return 0;
}
