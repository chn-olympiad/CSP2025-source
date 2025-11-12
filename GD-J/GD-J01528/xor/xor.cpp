#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=5e5+10;
int a[MAXN],n,k,ans;
bool specA=1,specB=1,specW=1;
int sum(int l,int r){
	int s=0;
	for(int i=l;i<=r;i++)s^=a[i];
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)specA=0;
		if(a[i]!=0&&a[i]!=1)specB=0;
		if(a[i]>=k)specW=0;
	}
	if(specW){
		cout<<0;
		return 0;
	}
	int last=0;
	if(!specA&&!specB){
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				last=i;
				ans++;
				continue;
			}
			for(int j=i;j>last;j--){
				if(sum(j,i)==k){
					last=i;
					ans++;
					break;
				}
			}
		}
	}
	if(specA){
		if(k==1){
			ans=n;
		}else if(k==0){
			ans=n/2;
		}
	}else if(specB){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i])cnt++;
		}
		if(k==1){
			ans=cnt;
		}else{
			ans=cnt/2;
		}
	}
	printf("%d",ans);
	return 0;
}
