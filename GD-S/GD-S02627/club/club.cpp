#include<bits/stdc++.h>
using namespace std;
int t;
long long ans = 0;
int a[100005][3],sl[3];
void sz(int x,int y,int z){
	int u = max(x,y);
	int maxx = max(u,z);
	if(maxx == x){
		sl[1]++;
	}if(maxx == y){
		sl[2]++;
	}if(maxx == z){
		sl[3]++;
	}ans+=maxx;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans = 0;
		int n;
		cin>>n;
		int m = n/2;
		for(int i = 1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}bool p = 0,olo = 0,lol = 0;
		int az[100005],ak[100005],ao[100005];
		
		for(int i = 1;i<=n;i++){
			if(a[i][2]!=0||a[i][3]!=0){
				p = 1;
			}if(a[i][2]!=0||a[i][1]!=0){
				olo = 1;
			}if(a[i][1]!=0||a[i][3]!=0){
				lol = 1;
			}
			az[i] = a[i][1];
			ak[i] = a[i][3];
			ao[i] = a[i][2];
		}if(p == 0){
			sort(&az[1],&az[n+1]);
			reverse(&az[1],&az[n+1]);
			for(int i = 1;i<=m;i++){
				ans+=az[i];
			}
		}else if(olo == 0){
			sort(&ak[1],&ak[n+1]);
			reverse(&ak[1],&ak[n+1]);
			for(int i = 1;i<=m;i++){
				ans+=ak[i];
			}
		}else if(lol == 0){
			sort(&ao[1],&ao[n+1]);
			reverse(&ao[1],&ao[n+1]);
			for(int i = 1;i<=m;i++){
				ans+=ao[i];
			}
		}
		else{
			
			for(int i = 1;i<=n;i++){
				if(sl[1]<m&&sl[2]<m&&sl[3]<m){
					sz(a[i][1],a[i][2],a[i][3]);
				}else if(sl[1]>=m){
					sz(-1,a[i][2],a[i][3]);
				}else if(sl[2]>=m){
					sz(a[i][1],-1,a[i][3]);
				}else if(sl[3]>=m){
					sz(a[i][1],a[i][2],-1);
				}
			}
		}cout<<ans<<endl;
		sl[1]=0;
		sl[2]=0;
		sl[3]=0;
	}return 0;
} 
