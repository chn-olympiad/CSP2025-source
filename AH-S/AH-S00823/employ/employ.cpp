#include<bits/stdc++.h>
using namespace std;
int m,n,c[510],s1[510],minn=1000,maxx;
int sum;
string a,s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		minn=min(minn,c[i]);
		maxx=max(maxx,c[i]);
	}
	for(int i=1;i<=n;i++)s1[i]=s[i]-'0';
	for(int i=1;i<=n;i++){
		if(maxx>s1[i]){
			for(int i=1;i<=n-1;i++){
				sum+=i;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
