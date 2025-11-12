#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,k,a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(k==0){
        int ret=0;
        for(int i=1;i<=n;i++)
            if(a[i]==0)
                ret++;
        for(int i=1;i<n;i++)
            if(a[i]==a[i+1]&&a[i]!=0)
                ret++,i++;
        cout<<ret;
        return 0;
    }
    if(k==1){
        int ret=0;
        for(int i=1;i<n;i++){
            if((a[i]==1&&a[i+1]==0)||(a[i]==0&&a[i+1]==1))
                ret++,i++;
            if(a[i]==1&&a[i+1]==1&&a[i+2]==1)
                ret++,i+=2;
        }
        cout<<ret;
    }
	return 0;
}
