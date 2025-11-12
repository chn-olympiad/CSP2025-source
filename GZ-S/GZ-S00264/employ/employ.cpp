//GZ-S00264 YangChengjin HLXX
#include<bits/stdc++.h>
using namespace std;
int n,m,dai,meow=1;
string s;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)if(s[i]=='0')dai++; 
	for(int i=n;i>=1;i--){
		if(s[i]=='1'){
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(dai<a[j])cnt++,a[j]=0;
			}
			if(cnt!=0)meow*=cnt;
		}
		else dai--;
	}
	cout<<meow;
	return 0;//by-ycj
}
