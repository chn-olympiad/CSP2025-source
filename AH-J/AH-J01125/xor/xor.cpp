#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k,maxn=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int ans=a[i];
            for(int k=i+1;k<=j;k++){
                ans^=a[k];
            }
            if(ans==k){
                cnt++;
                i+=j-i+1;
                maxn=max(maxn,cnt);
            }
        }
        cnt=0;
    }
    cout<<maxn;
	return 0;
}
