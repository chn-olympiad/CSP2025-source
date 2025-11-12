#include<bits/stdc++.h>
#define ll long  long
using namespace std;
const int N=5e5+10;
int n,k,id;
int k1[30];
int a[N];
int ans,num;
int flag;
int b[N][21];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		if(a[i]==k){
//			ans++;
//			id=i;
//		}
		if(a[i]==1) num++;
		if(a[i]!=1){
			flag=1;
		}
		if(a[i]>1){
			flag=2;
		}
	}
	if(k==1&&flag==0){
		flag=1;
	}
	if(flag==0){
		cout<<n/2;
	}
	else if(flag==1){
		if(k==1){
			ans=num;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}
				if(a[i]==1&&a[i-1]==1){
					ans++;
					a[i]=2;
				}
			}
		}
		cout<<ans;
	}
	else{
		
	}
	return 0;
}

/*
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1



*/
