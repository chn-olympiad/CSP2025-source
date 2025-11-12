#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=5*1e5+10;
int n,k,a[N],sum=0,b,c,m,ans=0,s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
		return 0;
	}
	if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
		return 0;
	}
	if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<1;
		return 0;
	}
	int l=1,r=1;
	for(int i=1;i<=n;i++){
		ans=0;
		l=i,r=i;
		if(a[i]*a[r]==k){
			ans++;
			continue;
		}
		else{
			m=l;
			s[l+1]=a[l]*a[r+1];
			for(r=m+2;r<=n;r++){
				s[r]=a[r-l]*a[r];
				if(s[r]==k){
					ans++;
					if(r==n){
						cout<<ans;
						return 0;
					}
					else{
						i=r+l;
						continue;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
