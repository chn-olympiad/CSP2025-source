#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,f=0,ans=0,p=0;
	cin>>n>>m;
	char a[n+5],b[n+5],c[n+5];
	cin>>a;
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) c[i]=i;
		for(int i=1;i<=n;i++){
		if(a[i]==1&&b[i]>ans) f+=1;
		if(f==m) {
			break;
			p+=1;
		}
	}
	cout<<p<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
