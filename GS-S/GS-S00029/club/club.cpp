#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int s;
	cin>>s;
	int a[100]={};
	for(int j=1;j<=s;j++){
		int n,maxv,cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			a=max(a,c);
			b=max(b,c);
			maxv=max(a,b);
			cnt+=maxv;
		}
		a[j-1 ]=cnt;
	}
	for(int i=0;i<=s-1;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
