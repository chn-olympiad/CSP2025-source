#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,k,R;
ll a[500005],b[500005];
ll cnt,x,ans;

struct Q{
	int ml,mr;
}q[500005];

bool cmp(Q a,Q b){
	return a.mr<b.mr; 
}
int main(){
	/*文件输入输出*/ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	/*输入*/ 
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	/*前缀和*/ 
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]^a[i];
	}
	
	/*暴力*/
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(l==1){
				x=b[r];
			}else{
				x=b[r]^b[l-1];
			}
			if(x==k){
				cnt++;
				q[cnt].ml=l;
				q[cnt].mr=r;
			}
		}
	}
	
	/*贪心*/ 
	sort(q+1,q+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(q[i].ml>R){
			ans++;
			R=q[i].mr;
		}
	}
	cout << ans;
	return 0;
}
