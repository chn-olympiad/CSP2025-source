#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=5e5+5;
int n,k,ans;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(a[1]==1){
		bool flag=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=1){
				flag=1;
				break;
			}
		if(!flag){
			cout<<n;
			return 0;			
		}
	}
	if(a[1]==1||a[1]==0){
		bool flag=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=0&&a[i]!=1){
				flag=1;
				break;
			}
		if(!flag){
			if(k==0){
				for(int i=1;i<=n;i++){
					if(a[i]==0)ans++;
					else if(a[i]==1&&a[i+1]==1){
						ans++;
						i++;
					}
				}
			}
			else if(k==1){
				for(int i=1;i<=n;i++){
					if(a[i]==1){
						if(a[i+1]==0&&i!=n){
							ans++;
							i++;
						}
						else ans++;
					}
					else{
						if(a[i+1]==1){
							ans++;
							i++;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
