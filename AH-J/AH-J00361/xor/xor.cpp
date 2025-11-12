#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans1,ans2;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
        cin>>a[i];
	}
	for(int i=0;i<n;i++){
        if(a[i]==k){
            ans1++;
        }
	}
	for(int i=1;i<n;i++){
        if(a[i-1]^a[i]==k){
            ans2++;
        }
	}
	cout<<max(ans1,ans2);
	return 0;
}
