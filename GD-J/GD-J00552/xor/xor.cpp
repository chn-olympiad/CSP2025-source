#include<bits/stdc++.h>
using namespace std;
struct f{
	int a,b;
}w[1000005];
int h[100005],n,k,l,ans,p,t;
bool cmp(f x,f y){
	return x.b<y.b;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans=h[i];
			for(int k=i+1;k<=j;k++){
				ans=ans^h[k];
			}
			if(ans==k){
				w[++l].a=i;
				w[l].b=j;
			}
		}
	}
	sort(w+1,w+1+l,cmp);
	for(int i=1;i<=l;i++){
		if(w[i].a>p){
			p=w[i].b;
			t++;
		}
	}cout<<t;
	return 0;
}
