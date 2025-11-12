#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[505];
int c[505];

bool flag;

long long d;

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	flag=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0')flag=0;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	
	if(m==n)cout<<0;
	else if(flag){
		d=1;
		for(long long i=2;i<=n;i++)
			d=d*i;
		cout<<d;
	}
	
	return 0;
}

