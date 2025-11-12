#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    long long x[n+1],x1[n+1]={0};
    int y=0;
    for(int i=1;i<=n;i++){
    	cin>>x[i];
    	if(x[i]==k){
    		y++;
    		x1[i]=1;
		}
	}
	cout<<y+1;
return 0;
}
