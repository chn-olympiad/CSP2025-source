#include<bits/stdc++.h>
using namespace std;
struct qu{
	long long x,y,chang;
};
qu a[1000001];
int b[1000001];
bool cmp(qu x,qu y){
	if(x.y<y.y)return true;
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,sum=0,l=0,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int p=0;
		for(int j=i;j<=n;j++){
			p=p^b[j];
			if(p==k){
				sum++;
				a[sum].x=i;
				a[sum].y=j;
				a[sum].chang=j-i+1;
			}
		}
	}
	sort(a+1,a+1+sum,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i].x>l){
			l=a[i].y;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}