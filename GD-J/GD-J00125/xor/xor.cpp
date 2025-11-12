#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=500005;

int n,k,cnt;
int a[N];
bool vis[N];

int xor_(int x,int y){
	string x_="",y_="",ans="";
	if(x==0)x_=x_+'0';
	if(y==0)y_=y_+'0';
	while(x){
		x_=x_+char(x%2+'0');
		x/=2;
	}
	while(y){
		y_=y_+char(y%2+'0');
		y/=2;
	}
	for(int i=0;i<min(x_.size(),y_.size());i++){
		if(x_[i]==y_[i])ans='0'+ans;
		else ans='1'+ans;
	}
	if(x_.size()>y_.size()){
		for(int i=y_.size();i<x_.size();i++){
			ans=ans+x_[i];
		}
	}
	else{
		for(int i=x_.size();i<y_.size();i++){
			ans=ans+y_[i];
		}
	}
	int l=0;
	for(int i=0;i<ans.size();i++){
		int p=pow(2,i);
		if(ans[i]=='1')l+=p;
	}
	return l;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1,sum=a[l];
			bool flag=false;
			for(int i=l+1;i<=r;i++){
				if(vis[i]==true){
					flag=true;
				}
				sum=xor_(sum,a[i]);
			}
			if(flag==false&&sum==k){
				for(int i=l;i<=r;i++){
					vis[i]=true;
				}
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
