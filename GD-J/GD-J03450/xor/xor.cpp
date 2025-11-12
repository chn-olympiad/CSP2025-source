#include<bits/stdc++.h>
using namespace std;
const int MS=5e5+10;
int n,k;
int s[MS]={},a[MS]={},ans=0,p,j;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	s[n+1]=s[n];
	for(p=0;p<=n;p++){
		for(j=p+1;j<=n;j++){
			if((s[j]^s[p])!=k)continue;
			ans++;
			p=j-1;
			break;
			
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
