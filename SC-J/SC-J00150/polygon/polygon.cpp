#include<bits/stdc++.h>
using namespace std;
int n,l[5050]={},t1=0,tm=0,ans=0;
bool b[5050]={};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&l[i]);
	}
	sort(l+1,l+n+1,cmp);
	while(b[n+1]==0){
		if(b[1]==0){
			b[1]=1;
			t1++;
		}
		else{
			b[1]=0;
			t1--;
		}
		int x=1;
		while(b[x]==0){
			x++;
			if(b[x]==0){
				b[x]=1;
				t1++;
			}
			else{
				b[x]=0;
				t1--;
			}
		}
		if(t1>=3){
			int t=0;
			for(int i=n;i!=0;i--){
				if(b[i]){
					t+=l[i];
					x=i;
				}
			}
			if(t>l[x]*2){
				ans++;
				ans%=998244353;
			}
		}
	}
	cout<<ans;
	return 0;
}