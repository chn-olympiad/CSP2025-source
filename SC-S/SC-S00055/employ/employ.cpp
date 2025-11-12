#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=5e2+50,mod=998244353;
int c[maxn],cnt;
string s;
long long int ans=1;
bool check(int x,int y)//x是否可以在y上
{
	int q1=0,q0=0;
	for(int i=1;i<=y;i++){
		if(s[i-1]-'0'==1){
			q1++;
		}
		else
		{
			q0++;
		}
	}
	q1--;
	printf("%d %d 2\n",q1,x-1-q0);
	if(q1<=x-1-q0){
		return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i-1]-'0'==1){
			cnt++;
		}
		
	}
	sort(c+1,c+1+n);
	if(cnt<m){
		cout<<"0";
		return 0;
	}
	
	
}