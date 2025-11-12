#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int a[N],n,k,v[N];
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=true;//A
	bool fb=true;
	int p=0,q=0;//p:1	q:0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			f=false;
		}
		if(a[i]!=0&&a[i]!=1)fb=false;
		if(a[i]==1)p++;
		if(a[i]==0)q++;
	}

	if(k==0&&f){//A
		cout<<0;
		return 0;
	}
	if(k==0){
		cout<<q;
		return 0;
	}
	if(fb){
		if(k==0)cout<<q;
		else cout<<p;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=a[i];
			for(int t=i+1;t<=j;t++){
				if(v[t]==1)break;
				else{
					x=(x ^ a[i]);
					
				}
			}
			if(k==x){
				ans=max(ans,(long long)(j-i+1));
				for(int t=i;t<=j;t++){
					v[i]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
//	cout<<(2 ^ 5);
