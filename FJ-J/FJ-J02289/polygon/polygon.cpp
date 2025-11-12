#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long sum=0;
int n;
int maxn;
int h;
int zc[5005];
void hs(int cd,int c,int j){
	if(c>cd){
		if(h>2*maxn){
			sum++;
			sum%=998244353;
			return;
		}else{
			return;
		}
	}
	for(int i=j;i<=n;i++){
		zc[c]=a[i];
		if(a[i]>=maxn){
			int maxm=maxn;
			maxn=a[i];
			h+=a[i];
			hs(cd,c+1,i+1);
			maxn=maxm;
			h-=a[i];
		}else{
			h+=a[i];
			hs(cd,c+1,i+1);
			h-=a[i];
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		hs(i,1,1);
	}
	cout<<sum;
	return 0;
}
