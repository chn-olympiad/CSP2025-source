#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,a[N],cnt1;
//int f[N][N];
int ans;
bool v[N],t2=true;
bool check(int s,int l){
	int res=a[s];
	if(v[s])return false;
//	if(res==k)return true;
	for(int i=s+1;i<s+l;i++){
		if(v[i])return false;
		res^=a[i];
	}
	return res==k;
}
//bool xors(int e,int l){
//	int res=a[e];
//	for(int i=e-l+1;i<e;i++){
//		res^=a[i];
//	}
//	return res==k;
//}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(t2){
			if(a[i]>1){
				t2=false;
			}
			if(a[i]==1){
				cnt1++;
			}
		}
	}
//	for(int e=1;e<=n;e++){
//		f[e][1]=(a[e]==k);
//		for(int l=2;l<=e;l++){
//			f[e][l]=f[e][l-1]+f[e-1][l-1];
//			if(f[e][l]==0){
//				f[e][l]+=xors(e,l);
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[j][i]<<" ";
//		}cout<<endl;
//	}
//	cout<<f[n][n];
	if(t2){
		cout<<cnt1;
	}else{
		for(int l=1;l<=n;l++){
			for(int s=1;s<=n-l+1;s++){
				if(check(s,l)){
					ans++;
//					cout<<s<<" "<<l<<endl;
					for(int i=s;i<s+l;i++){
						v[i]=true;
					}
				}
			}
		}
		cout<<ans;
	}
}
