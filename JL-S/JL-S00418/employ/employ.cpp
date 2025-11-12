#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0,cc=1;
	cin>>n>>m;
	char s[n];
	int c[n];
	cin>>s;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<501;i++){
		cnt=0;
		for(int j=0;j<n;j++){
			if(c[j]==i) cnt++;
		}
		if(cnt==0) cnt++;
		cc=cc*cnt;
	}
	cout<<cc+1;
	return 0;
}
