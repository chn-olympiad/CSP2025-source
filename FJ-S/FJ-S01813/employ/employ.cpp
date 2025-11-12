#include <bits/stdc++.h>
using namespace std;
int c[505],d[505],cnt[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(s[1]==0){
		d[1]=1;
	}else{
		d[1]=0;
	}
	for(int i=2;i<=n;i++){
		if(s[i]==0){
			d[i]=d[i-1]+1;
		}else{
			d[i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(c[j]<d[i]){
				cnt[j]++;
			}
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		if(cnt[i]!=0){
			ans*=cnt[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=0){
			ans*=c[i];
		}
	}
	cout<<ans;
	return 0;
}
