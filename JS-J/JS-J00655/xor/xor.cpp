#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5;
ll a[N];

int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
    for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j&&a[i]==k)ans++;
			else{
				int x=0;
				for(int u=i;u<=j;u++){
					x^=a[i];
				}
				if(x==k)ans++;
			}
		}
	}
    return 0;
}

