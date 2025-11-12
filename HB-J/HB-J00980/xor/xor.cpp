#include<bits/stdc++.h>

using namespace std;
int n,k;
int a[500005],s[500005],book[500005],flag,ans;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            if((s[j+i]^s[j])==k)
            {
                flag=0;
                for(int l=j+1;l<=j+i;l++){
                    if(book[l]==1)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    ans++;
                    for(int l=j+1;l<=j+i;l++)
                        book[l]=1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
/*
4 3
2 1 0 3
*/
