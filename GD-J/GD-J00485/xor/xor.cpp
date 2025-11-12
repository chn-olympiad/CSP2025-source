#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k;
int a[maxn];
int s[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    int ans=0;
    int l=0;
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=i;j>l;j--){
            tmp^=a[j];
            if(tmp==k){
                ans++;
                l=i;
                break;
            }
        }
//        cout<<l<<' ';
    }
    cout<<ans;
}
