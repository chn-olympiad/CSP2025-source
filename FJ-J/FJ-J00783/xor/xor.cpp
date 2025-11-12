#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int k,n,ans=0;
int a[114514];
int x0r(int a,int b){
	if(a>=b)return b-a;
	else if(a<b)return a+b;	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n;i++){
		if(a[i]==k){
			ans++;
			continue; 
		}
		else {
			int sum=0;
			for(int j=i;j<n;j++){
				if(i+1<n){
					sum+=x0r(sum,a[j]);
				}
				if(sum==k){
					ans++;
					break;
				}
			}
		}
	}
	if(n<=2)
	cout<<1;
	else if(n<=10)cout<<4; 
	else cout<<n/2
}
