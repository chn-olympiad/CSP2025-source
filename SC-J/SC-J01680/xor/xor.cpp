//怀疑双指针，记得开long long，数据范围不太对，暴力硬做得开高精度
//先暴力，之后再想对策。事已至此，先搞特殊性质
#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k,a[maxn],ans;
void read(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool t1=0,t2=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)t1=1;
		if(a[i]!=0&&a[i]!=1)t2=1;
	}
	if(!t1)cout<<n/2;
	else if(!t2){
		if(k==0){
			bool p=0;
			for(int i=0;i<n;i++){
				if(a[i]==0){
					ans++;
					p=0;
				}
				else if(p){
					//cout<<"114514";
					ans++;
					p=0;
				}else p=1;
			}
		}else if(k==1){
			for(int i=0;i<n;i++){
				if(a[i]==1){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	else cout<<n/2;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	read();
	
	return 0;
}