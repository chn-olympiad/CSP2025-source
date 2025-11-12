//GZ-S00302 都匀二中 潘祖镇 
#include<bits/stdc++.h>
using namespace std;
int n,m,p=0;
char s[505];
int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='1')t++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(t<m)cout<<0;
	else {
		for(int i=1;i<=n;i++){
			int ans=0,N=n,xin=0;
			for(int j=1;j<=n;j++){
				
			}
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
