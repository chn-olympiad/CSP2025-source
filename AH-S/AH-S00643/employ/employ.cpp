#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,cnt=0,ans=1;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1,a;i<=n;i++){
		cin>>a;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			cnt++;
		}
	}
	int l=s.size();
	for(int i=l-1;i>=l-cnt+1;i--){
		ans*=i;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
