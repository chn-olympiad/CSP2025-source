#include<bits/stdc++.h>
using namespace std;
int n,a[10005],ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
		for(int i=0;i<n;i++){
		cin>>a[i];
		}
		for(int i=0;i<n;i++){
			if(a[i]%2==0){
				ans++;
				}
			}
			for(int i=0;i<n;i++){
				cout<<ans;
				}
		return 0;
	}
