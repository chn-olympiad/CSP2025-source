#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
int f(int a1,int a2){
	return a1^a2;
}
int sqr_n(int x,int y){
	int a=1;
	for(int i=1;i<=y;i++){
		a*=x;
	}
	return a;
}
int n;
int k;
int a[500010];
int res=0;
int findX(int x,int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){
		if(a[i]==x)ans++;
	}
	return ans;
}
int g(int l,int r){
	int ans=0;
	ans=f(l,l+1);
	for(int i=l+2;i<=r;i++){
		ans=f(ans,a[i]);
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(k==0){
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				if(findX(1,l,r)%2==0&&findX(2,l,r)%2==0){
					res++;
				}
			}
		}
		cout<<res;
		return 0;
	}//×îÉÙ10·Ö
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(g(l,r)==1)res++;
		}
	}
	cout<<res;
	return 0;
}
