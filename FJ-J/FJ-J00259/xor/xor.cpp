#include<bits/stdc++.h>
using namespace std;
struct node{int x,y;};
bool cmp(node g,node h){
	return g.y<h.y;
}
int n,k,ans,a[500005],b[500005];
bool tp0=true,tp1=true,tp01=true; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		b[i]=b[i-1]^a[i];
		if (a[i]!=0){
			tp0=false;
		}
		if (a[i]!=1){
			tp1=false;
		}
		if (a[i]!=0||a[i]!=1){
			tp01=false;
		}
	}
	/*
	if (n<=10000){
		vector<node> f;
		for (int i = 1;i <= n;i++){
			for (int j = i;j <= n;j++){
				if ((b[j]^b[i-1])==k){
					//cout << i << " " << j << endl;
					f.push_back({i,j});
				}
			}
		}
		sort(f.begin(),f.end(),cmp);
		//for (node i : f) cout << i.x << " " << i.y << endl;
		int mind=0,fs=f.size();
		for (int i = 0;i < fs;i++){
			if (f[i].x>mind){
				mind=f[i].y;
				ans++;
			}
		}
	}
	*/
	if (tp0||tp1){
		if (tp0){
			if (k!=0){
				cout << 0;
			}else{
				cout << n;
			}
		}
		else if (tp1){
			if (k==0){
				cout << n/2;
			}else if (k==1){
				cout << n;
			}else{
				cout << 0;
			}
		}
		return 0;
	}
	else if (tp01){
		if (k>1){
			cout << 0;
			return 0;
		}else if (k==1){
			for (int i = 1;i <= n;i++){
				if (a[i]==1){
					ans++;
				}
			}
			cout << ans;
			return 0;
		}
	}
	int mind=0;
	for (int i = 1;i <= n;i++){
		for (int j = i;j > mind;j--){
			if ((b[j-1]^b[i])==k){
				mind = i;
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
/*
最坏情况：n(n+1)/2=O(n^2)
一般情况：ans(n/ans)(n/ans+1)/2=O(n^2/ans)
最优情况：n=O(n),or O(1)(所有a[i]=1or0)
*/
