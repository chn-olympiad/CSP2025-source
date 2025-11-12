#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5000005],top=0;
int d[5000005];
bool cmp(int x,int y){return x>y;}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,flag=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){cin>>a[i];if(a[i]!=0&&a[i]!=1) flag=1;}
	if(!flag){
		int his=0,ans=0;
		for(int i=1;i<=n+1;i++){
			if(his==k) ans++,his=0;
			else if(his>k){his=0;}
			if(his!=0) his=(his^a[i]);
			else{
				if(a[i]==k) ans++;
				else his=a[i];
			}
		}
		cout<<ans;	
	}else{
		int ans=0; 
		for(int i=1;i<=n;i++){
			int flag1=0;
			if(top!=0){
				int wei=0;
				for(int j=1;j<=top;j++){
					if((a[i]^d[j])==k){flag1=1;top=0;ans++;break;}
					d[j]=(d[j]^a[i]);
				}
			}
			if(!flag1){
				if(a[i]==k) ans++,top=0;
				else d[++top]=a[i];
			}		
		}
		cout<<ans;
	}
	return 0;
}
//while(1) rp++;