#include <bits/stdc++.h>
const int N=1e5+101; 
using namespace std;
int n,a[N],b[N],c[N],x[N],mx = -99;
void dfs(int x[N],int cnt){
	if(cnt == n){
//		for(int i = 1;i<=n;i++){
//			cout<<x[i]<<" ";
//		}
//		cout<<"\n";
		int c1=0,c2=0,c3=0,f=0,sum=0;
		for(int i = 1;i<=n;i++){
			if(x[i] == 1){
				c1++;
				sum+=a[i];
				if(c1 > n/2){
					f = 1;
					break;
				}
			}if(x[i] == 2){
				c2++;
				sum+=b[i];
				if(c2 > n/2){
					f = 1;
					break;
				}
				if(c2 > n/2)f=1;
			}if(x[i] == 3){
				c3++;
				sum+=c[i];
				if(c3 > n/2){
					f = 1;
					break;
				}
			}
		}
		if(f==0){
			mx = max(mx,sum);
		}
		return;
	}
	for(int i = 1;i<=3;i++){
		x[cnt + 1] = i;
		dfs(x,cnt+1);
		x[cnt+1] = 0; 
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		mx = -999;
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(x,0);
		cout<<mx<<"\n";
	}
	return 0;
} 
