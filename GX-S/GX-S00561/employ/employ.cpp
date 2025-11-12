#include<bits/stdc++.h>
using namespace std;
long long CC(int n,int m){
	int sy=1,st=1,sss=m,i=n;;
	while(sss!=0){
		sss--;
		sy*=i;--i;
	}
	for(int i=m;i>=1;i--)st*=i;
	sy/=st;
	return sy;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)if(s[i]=='1')a++;
	if(m==1)cout<<n;
	else if(m==n)cout<<1;
	else if(a==n)cout<<CC(n,m);
	return 0;
}
