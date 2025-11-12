#include<bits/stdc++.h>
using namespace std;
long long n,m,c[510],d[510],sum;string s;
long long abc(long long x,long long y){
	if(x<n){
		for(long long i=0;i<n;i++){
			if(d[i]!=1){
				d[i]=1;
				if(c[i]<=y || s[x-1]=='0'){
					abc(x+1,y+1);
				}else abc(x+1,y);
				d[i]=0;
			}
		}
	}else {
		for(long long i=0;i<n;i++){
			if(d[i]!=1 && c[i]<=y)y++;
		}
		if(n-y>=m)sum++;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=0;i<n;i++)cin>>c[i];
	abc(1,0);
	cout<<sum;
 return 0;
}
