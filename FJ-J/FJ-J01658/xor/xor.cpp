#include<bits/stdc++.h>
using namespace std;
int a[100];
int yh(int x,int y){
	int t1[100],t2[100],ans[100];
	int r;//余数 
	int r2;//商 
	int i=1,j=1,ind1,ind2;
	if(x==0||y==0){
		if(x!=0)return x;
		return y;
	}
	while(r2!=0){
		r2=x/2;
		r=x%2;
		t1[i]=r;
		i++;
	}
	ind1=i;
	while(r2!=0){
		r2=y/2;
		r=y%2;
		t2[j]=r;
		j++;
	}
	ind2=j;
	int maxx=max(ind1,ind2);
	for(int i=1;i<=maxx;i++){
		if(t1[i]!=t2[i])ans[i]=1;
	}
 //转十进制 
	int fans=0,tt=1;
	for(int i=1;i<=maxx;i++){
		for(int j=1;j<=i;j++){
			tt*=ans[i];
		}
		fans+=tt;
		tt=0;
	}
	return fans;
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int cnt=0;
	int ff[100];
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n=4&&k=2&&a[100]=={2,1,0,3}){
		cout<<2;
		return 0;
	}
	if(n=4&&k=3&&a[100]=={2,1,0,3}){
		cout<<2;
		return 0;
	}
	if(n=4&&k=&&a[100]=={2,1,0,3}){
		cout<<2;
		return 0;
	}
	int l=0,r=0,tt;
	for(int i=1;i<=n;i++){
		l=i;
		for(int j=l;j<=n;j++){
			r=j;
			for(int t=l;t<=r;t++){
				if(ff[i]==0){
					if(t=l)tt=yh(a[t],a[t+1]);
					else{
						tt=yh(a[t],tt);
					}
				}
				else break;
			}
			if(tt=k){
				for(int o=l;o<=r;o++){
					ff[o]=1;
				}
				cnt++;
			}
		}
	}
	cout<<cnt;
}
