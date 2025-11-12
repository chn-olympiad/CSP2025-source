#include<iostream>
#include<cmath>
using namespace std;
int n,k,sum,jin;
int a[5000005];
struct qu{
	int l,r;
};
qu jian[5000005];
int maxnfen=0;
void ju(int l,int r,int got,int i){
	if(i>jin){
		maxnfen=max(got,maxnfen);
		return;
	}
	if(jian[i].l<=r){
		return;
	}
	ju(l,jian[i].r,got+1,i+1);
//	if(i+1<=jin&&jian[i+1].l<=jian[i].r){
		ju(l,r,got,i+1);
//	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	int all1=1;
	int all01=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
		all1=0;
		if(a[i]!=1&&a[i]!=0)
		all01=0;
	}
	if(all1){
		if(k==1)
		cout<<n;
		else if(k==0)
		cout<<ceil(n*1.0/2);
		else
		cout<<0;
		return 0;
	}
	if(n>40){
			for(int i=1;i<=n;i++){
		int ans=0;//任何数^0=原数
		for(int j=i;j<=n;j++){
			ans^=a[j];
			if(ans==k){
//				cout<<i<<' '<<j<<endl;
				i=j;
				sum++;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
	}
	for(int i=1;i<=n;i++){
		int ans=0;//任何数^0=原数
		for(int j=i;j<=n;j++){
			ans^=a[j];
			if(ans==k){
				jian[++jin].l=i;
				jian[jin].r=j;
				sum++;
				break;
			}
		}
	}
	ju(0,0,0,1);
	cout<<maxnfen;
	return 0;
}
