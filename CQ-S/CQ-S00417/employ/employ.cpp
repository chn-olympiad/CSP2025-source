#include<bits/stdc++.h>
using namespace std;
int n,m,c[500],f,ff=1;
long long p=998244353,h;
string s;
int main(){
	freopen("employ3.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	sort(c,c+n);
	int i=0,j=0;
	while(i<s.length()&&j<n){
		if(s[i]=='0')ff=0;
		while(s[i]=='0')i++;
		while(c[j]<i)j++;
		i++;
		j++;
		f++;
	}
	if(f<m){
		cout<<0;
		return 0;
	}
	if(ff){
		h=1;
		for(long long i=0;i<m;i++){
			h*=n-i;
			h%=p;
		}
		cout<<h;
		return 0;
	}
	cout<<1;
}
