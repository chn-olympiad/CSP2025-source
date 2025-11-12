#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int f[500010];
int head=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int flag=1,flag2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0; 
		if(a[i]!=1 and a[i]!=0) flag2=0;
		f[i]=f[i-1]|a[i];
	}
	if(flag){
		if(k==0) cout<<n/2;
		else if(k==1) cout<<n;
		else cout<<0;
	}else if(flag2){
		if(k>1) cout<<0;
		else{
			int one=0,zero=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) one++;
				else zero++;
			}
			cout<<one;
		}
	}else{
		int flag[500010],ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				int temp=0;
				int st=1;
				for(int x=j;x<=i;x++){
					temp=temp|a[x];
					if(flag[x]==1){
						st=0;
						break;
					}
				}
				if(temp==k and st){
					for(int x=j;x<=i;x++){
						flag[x]=1;
					}
					ans++;
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


