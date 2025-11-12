#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],ans=INT_MIN;
bool vis[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    int flag=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]==0){
    		flag++;
    		a[i]=1,a[n+flag]=1;
		}
    	if(a[i]!=1){
    		flag=-1;
		}
	}
	if(flag!=-1){
		if(n>k || (n+flag)/3>=k || (n+flag)/3+(n+flag-(n+flag)/3*3)>=k){
			cout<<k;
		}
		else{
			cout<<"0";
		}
	}
	return 0;
}
