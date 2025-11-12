#include<bits/stdc++.h>
using namespace std;
int n,k; 
int a[500005],xorb[500005],cnt[500005];
struct MT{
	int l,r;
}tmtbl[1000005];
bool cmp(MT a,MT b){
	if(a.r!=b.r){
		return a.r<b.r;
	}else{
		return a.l<b.l;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		xorb[i]=xorb[i-1]^a[i];
		cnt[a[i]]++;
	}
	if(cnt[1]==n&&k==0){
		cout << n/2;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int p=xorb[j]^xorb[i-1];
			if(p==k){
				ans++;
				tmtbl[ans].l=i,tmtbl[ans].r=j; 
			}
		}
	}
	sort(tmtbl+1,tmtbl+1+ans,cmp); 
	int newr=tmtbl[1].r,result=1;
	for(int i=2;i<=ans;i++){
		if(newr<tmtbl[i].l){
			newr=tmtbl[i].r;
			result++;
		}
	} 
	cout << result;
	return 0;
}  
