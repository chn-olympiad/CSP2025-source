#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
int n;
int a[5005];
long long ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		int count=0;
		int bs=1;
		for(int j=i+1;j<n;j++){
			count+=a[j];
			bs++;
			if(bs>=3&&count>a[i]){
				ans++;
				ans%=MOD;
				int de_bs=0;
				int de_count=0;
				for(int m=j-1;m>i;m--){
					de_bs++;
					de_count+=a[m];
					if(bs-de_bs>=3&&count-de_count>a[i]){
						ans++;
						ans%=MOD;
					}else break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
