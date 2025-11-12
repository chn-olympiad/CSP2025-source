#include<bits/stdc++.h>
using namespace std;
int n,a[500010][30],k,b[30],l=1,w[30],ans,s[500010],p[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n*n<=1e9){
		cin>>s[1];
		p[1]=s[1];
		for(int i=2;i<=n;i++){
			cin>>s[i];
			p[i]=p[i-1]^s[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=l;j<=i;j++){
				if(j==1){
					if(p[i]==k){
						ans++;
						l=i+1;
					}
				}
				else if((p[i]^p[j-1])==k){
					ans++;
					l=i+1;
					break;
				}
			}
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
			int t;
			cin>>s[i];
			t=s[i];
			for(int j=1;j<=20;j++){
				a[i][j]=t&1;
				t>>=1;
			}
		}
		int t=k;
		for(int i=1;i<=20;i++){
			b[i]+=t&1;
			t>>=1;
		}
		for(int i=1;i<=n;i++){
			if(s[i]==k){
				for(int j=1;j<=20;j++){
					w[j]=0;
				}
				ans++;
			}
			else{
				int flag=0;
				for(int j=1;j<=20;j++){
					w[j]+=a[i][j];
					w[j]%=2;
					if(w[j]!=b[j]){
						flag=1;
					}
				}
				if(flag==0){	
					for(int j=1;j<=20;j++){
						w[j]=0;
					}
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}