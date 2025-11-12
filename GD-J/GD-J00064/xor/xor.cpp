#include <bits/stdc++.h>
using namespace std;
int n,k,t,ans;
int a[500005],vis[500005],h[500005];
struct cc{
	int x,y,l,z;
}s[25000005];
inline bool cmp(cc x,cc y){
	if(x.z!=y.z){
		return x.z<y.z;
	}else{
		return x.l<y.l;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = i ; j <= n ; j++){
			int sum=0;
			for(int k = i ; k <= j ; k++){
				sum=int(sum^a[k]);
			}
			if(sum==k){
				t++;
				s[t].l=j-i+1;
				s[t].x=i;
				s[t].y=j;
			}
		}
	}
	for(int i = 1 ; i <= t ; i++){
		for(int j = s[i].x ; j <= s[i].y ; j++){
			h[j]++;
		}
	}
	for(int i = 1 ; i <= t ; i++){
		int su=0;
		for(int j = s[i].x ; j <= s[i].y ; j++){
			su=max(su,h[j]);
		}
		s[i].z=su;
	}
	sort(s+1,s+1+t,cmp);
	for(int i = 1 ; i <= t ; i++){
		int pd=0;
		for(int j = s[i].x ; j <= s[i].y ; j++){
			if(vis[j]){
				pd=1;
				break;
			}	
		} 
		if(pd==1)continue;
		for(int j = s[i].x ; j <= s[i].y ; j++){
			vis[j]=1;	
		} 
		ans++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
