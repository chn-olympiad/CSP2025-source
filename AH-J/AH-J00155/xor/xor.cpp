#include<bits/stdc++.h>
using namespace std;
int n,m;
int s=0;
int a[100005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++){
	   cin>>a[i];
	   if(a[i]==1){
		   s++;
	   }
	}
	cout<<s;
}
