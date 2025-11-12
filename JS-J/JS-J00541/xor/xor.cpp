#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[600005];
bool vis[600005];
int ans1,ans2,temp,ans;

int findtarget(int x,int y){
	for(int j=x+1;j<=n;j++){
		if(a[j]==y){
			return j+1;
		}
	}
	return -1;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;

	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(k==0 && a[i]==0){
			ans2++;
		}
		else if(k==1 && a[i]==1){
			ans2++;
		}
	}
	
	if(k==0){
		int i=1;
		while(i<=n && i!=-1){
			if(a[i]==0){
				i++;
				ans1++;
			}
			if(a[i]==1){
				int m=i;
				i=findtarget(i,1);
				if(i!=-1){
					ans1++;
				}
				else{
					ans1+=n-m;
				}
			}
		}
	}
	else if(k==1){
		int i=1;
		while(i<=n && i!=-1){
			if(a[i]==0){
				i=findtarget(i,1);
				if(i!=-1){
					ans1++;
				}
			}
			if(a[i]==1){
				ans1++;
				i++;
			}
		}
	}
	ans=max(ans1,ans2);
	cout<<ans;
	return 0;
}
