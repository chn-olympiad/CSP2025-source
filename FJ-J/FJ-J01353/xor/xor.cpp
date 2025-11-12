#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],f,p;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			f=1;
		}
		else{
			f=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1||a[i]==0){
			p=1;
		}
		else{
			p=0;
		}
	}
	if(n==1){
		if(a[1]==k){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(f==1){
		if(k==1){
			cout<<n;
			return 0;
		}
		if(k==0){
			if(n%2==0){
				cout<<n/2;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}
		cout<<0;
		return 0;
	}
	if(n==2&&p==1){
		if(k==1){
			if(a[1]==1&&a[2]==1){
				cout<<2;
				return 0;
			}
			if(a[1]==0&&a[2]==1){
				cout<<1;
				return 0;
			}
			if(a[1]==1&&a[2]==0){
				cout<<1;
				return 0;
			}
			if(a[1]==0&&a[2]==0){
				cout<<0;
				return 0;
			}
		}
		if(k==0){
			if(a[1]==1&&a[2]==1){
				cout<<1;
				return 0;
			}
			if(a[1]==0&&a[2]==1){
				cout<<0;
				return 0;
			}
			if(a[1]==1&&a[2]==0){
				cout<<0;
				return 0;
			}
			if(a[1]==0&&a[2]==0){
				cout<<1;
				return 0;
			}
		}
	}
	
	

	return 0;
}

