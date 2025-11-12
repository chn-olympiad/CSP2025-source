#include<bits/stdc++.h>
using namespace std;
const int mod=268000001;
int a[268000005],b[268000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	while(n--){
		string s,t;
		cin>>s>>t;
		int l=0,r=s.size()-1,y=0;
		while(s[l]==t[l]) l++;
		while(s[r]==t[r]) r--;
		for(int i=l; i<=r; i++)
			y=((y*29)%mod+t[i]-'a')%mod;
		b[y]++;
	}
	while(m--){
		string s,t;
		cin>>s>>t;
		int l=0,r=s.size()-1,y=0;
		while(s[l]==t[l]) l++;
		while(s[r]==t[r]) r--;
		for(int i=l; i<=r; i++)
			y=((y*29)%mod+t[i]-'a')%mod;
		printf("%d\n",b[y]);
	}
	return 0;
}
