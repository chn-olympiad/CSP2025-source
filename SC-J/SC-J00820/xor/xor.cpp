#include<bits/stdc++.h> 
using namespace std;
int n,k,a[500005][23],p,cnt[100000],m,h,ans[20],t,aans[20];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>cnt[i];
		if(cnt[i]==1){
    		p++;
		}
    	if(cnt[i]==0&&cnt[i-1]==0){
    		m++;
    		cnt[i]=1;
		}
    	
	}
	if(k==0&&p==n){
		cout<<n/2;
		return 0;
	}
	if(k==0&&p!=n){
		cout<<n-p;
		return 0;
	}
	if(k==1&&p!=n){
		cout<<p+m;
		return 0;
	}
	return 0;
}
