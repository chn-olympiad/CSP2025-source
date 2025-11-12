#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans;
bool vis[N];
struct node{
	int sta,en,by_sort;
}ansid[N];
bool cmp(node x,node y){
	if (x.by_sort!=y.by_sort) return x.by_sort<y.by_sort;
	else if (x.sta!=y.sta) return x.sta<y.sta;
	return x.en<y.en;
}
bool check(int i){
	for (int k=ansid[i].sta; k<=ansid[i].en; k++){
		if (vis[k]==true) return false;
	}
	for (int k=ansid[i].sta; k<=ansid[i].en; i++) vis[k]=true;
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k; // (^)
	for (int i=1; i<=n; i++) cin>>a[i];
	//
	bool flag1=true;
	for (int i=1; i<=n; i++){
		if (a[i]!=1){
			flag1=false;
			break;
		}
	}
	if (flag1==true && k==0){
		cout<<n/2<<endl;
		return 0;
	}
	//
	bool flag2=true;
	for (int i=1; i<=n; i++){
		if (a[i]>1){
			flag2=false;
			break;
		}
	}
	if (flag2==true){
		if (k==0){
			int ans_in_spe=0;
			for (int i=1; i<=n; i++){
				if (a[i]==0)  ans_in_spe++;
				else if (a[i]==1 && a[i+1]==1){
					ans_in_spe++;
					i++;
				}	
			}
			cout<<ans_in_spe<<endl;
			return 0;
		}
		else{
			int ans_in_spe=0;
			for (int i=1; i<=n; i++){
				if (a[i]==1) ans_in_spe++;
			}
			cout<<ans_in_spe<<endl;
		}
	}
	//
	int id=0;
	for (int len=1; len<=n; len++){
		for (int l=1; l<=n; l++){
			int r=l+len-1,tmp=a[l];
			if (r>n) break;
			for (int i=l+1; i<=r; i++) tmp^=a[i];
			if (tmp==k){
				ansid[++id].sta=l;
				ansid[id].en=r;
			}
		}
	}
	for (int i=1; i<=id; i++) ansid[i].by_sort=ansid[i].en-ansid[i].sta;
	sort(ansid+1,ansid+id+1,cmp);
	for (int i=1; i<=id; i++){
		if (check(i)) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
