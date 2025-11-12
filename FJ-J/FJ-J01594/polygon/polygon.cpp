#include<bits/stdc++.h>
using namespace std;
int n,a[5001],sum;
bool flag[5001]={true};
void thr(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;i<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]==2*max(a[j],max(a[i],a[k])))sum++;
			}
		}
	}
}

void f(int s,int mmax){
	int t=0;
	
	if(t>=3){
		if(s>mmax*2)sum++;
	}
	if(t==n)return;
	for(int i=1;i<=n;i++){
		if(flag[i]=false){
			continue;
		}
		t++;
		flag[i]=false;
		s+=a[i];
		mmax=max(mmax,a[i]);
		f(s,mmax);
		flag[i]=true;
	}
}
int main(){
	freopen("polygon1.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3)thr();
	else f(0,0);
	cout<<sum;
}
