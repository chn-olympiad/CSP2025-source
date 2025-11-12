#include<bits/stdc++.h>
using namespace std;
long long n,k,l,y,w,s;
long long a[100010];
int flag=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]!=1 && a[i]!=0){
    		flag=1;
		}
		else if (a[i]==0){
			flag=2;
		}
		if (a[i]==0)l++,w=0;
		else if (a[i]==1)y++,w++;
		if (w%2==0 && w!=0)s++;
	}
	if (flag==0){
		if (k==0)cout<<n/2;
		return 0;
	}
	else if (flag==2){
		if (k==0)cout<<l+s;
		else if (k==1)cout<<y;
		return 0;
	}
    return 0;
}
