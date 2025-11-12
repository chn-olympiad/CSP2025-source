#include<bits/stdc++.h>
using namespace std;
int T,d[4],c[100001],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(d,0,sizeof(d));
		int n;
		cin>>n;
		int a[4][n+1],b[4],t=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			b[1]=a[1][i];
			b[2]=a[2][i];
			b[3]=a[3][i];
			c[a[1][i]]=1;
			c[a[2][i]]=2;
			c[a[3][i]]=3;
			sort(b+1,b+4);
			if(d[c[b[3]]]<t){
				ans+=b[3];
				d[c[b[3]]]++;
			}else if(d[c[b[2]]]<t){
				ans+=b[2];
				d[c[b[2]]]++;
			}else{
				ans+=b[1];
				d[c[b[1]]]++;
			}
			
		}
		cout<<ans;
	}
	return 0;
}
