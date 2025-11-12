#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
const int N=5e5+5;
int n,k,num;
int a[N],p[N],no[N],nu[N][2],count1=0;
bool _1=1,_2=1;
int main(){
	fre("xor");
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)_1=0;
		if(a[i]!=1&&a[i]!=0)_2=0;
		if(a[i]==1)count1++;
		for(int j=i;j>=1;j--){
			if(!p[j]){
				no[j]=no[j]^a[i];
				if(no[j]==k){
					p[i]=j;
					break;
				}
			}
		}
	}
	if(_1){
		if(k==0){
			cout<<n/2;
		}
		else if(k==1)cout<<n;
		return 0;
	}
	if(_2){
		if(k==1){
			cout<<count1;
		}
		else if(k==0){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0)cnt++;
				else if(a[i-1]==1)cnt++;
			}
			cout<<cnt;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(p[i])nu[i][1]=1+max(nu[p[i]-1][1],nu[p[i]-1][0]);
		else nu[i][1]=nu[i-1][1];
		nu[i][0]=max(nu[i-1][1],nu[i-1][0]);
	}
	cout<<max(nu[n][1],nu[n][0]);
	return 0;
}