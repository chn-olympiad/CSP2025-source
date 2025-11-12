#include<bits\stdc++.h>
using namespace std;
int n,m,ans;
int a[500005],s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	if(m==0){
		if(s[n]==n)cout<<n/2;
		if(a[1]==0)ans++; 
		else for(int i=2;i<=n;){
			if(a[i]==1&&a[i+1]==1){i+=2;ans++;}
			else if(a[i]==0){ans++;i++;}
			else i++;
		}
	}
	else cout<<0;
	return 0;
}
