#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,a[500005],ans,h,t,one;
void specialB(){
	int num=a[0];
	for(int i=1;i<n;i++){
		num ^= a[i];
		if(num==k){
			ans++;
			num=a[i+1];
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int maxn,minn=2;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		maxn=max(a[i],maxn);
		minn=min(a[i],minn);
		if(a[i]==1) one++;
	}
	if(k<=1 && minn<2){
		if(k==0){
			ans=one%2;
		}else{
			ans = one;
		}printf("%d",ans);
		return 0;
	}
	
	int num=a[0];
	for(int i=1;i<n;i++){
		num ^= a[i];
		if(num==k){
			ans++;
			num=a[i+1];
		}
	}
	printf("%d",ans);
	return 0;
}
