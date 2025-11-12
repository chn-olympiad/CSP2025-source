#include<bits/stdc++.h>
using namespace std;
int n,ans,x,y,z;
struct manyi{
	int aone,atwo,athree;
}a[100010];
void dfs(int f,int sum){
	if(f>n){
		ans=max(ans,sum);
		return;
	}
	if(x<n/2){
		x++;
		dfs(f+1,sum+a[f].aone);
		x--;
	}
	if(y<n/2){
		y++;
		dfs(f+1,sum+a[f].atwo);
		y--;
	}
	if(z<n/2){
		z++;
		dfs(f+1,sum+a[f].athree);
		z--;
	}
}
bool cmp(manyi r,manyi t){
	return r.aone>t.aone;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin >> a[i].aone >> a[i].atwo >> a[i].athree;
		}
		if(n<=30){
			dfs(1,0);
			cout<<ans<<endl;
		}else{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(a[i].aone>a[i].atwo&&x<n/2){
					x++;
					ans+=a[i].aone;
				}else if(a[i].atwo>a[i].aone&&y<n/2){
					y++;
					ans+=a[i].atwo;
				}else if(x<n/2){
					x++;
					ans+=a[i].aone;
				}else if(y<n/2){
					y++;
					ans+=a[i].atwo;
				}
			}
			cout<<ans;
		}
		
	}
	return 0;
}
