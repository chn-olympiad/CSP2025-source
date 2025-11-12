#include<bits/stdc++.h>
using namespace std;
int sum,a[5010],z;
int main(){
    //freopen("polygon.in","r",stdin);
    //freoprn("polygon.out","r",stdout);
    cin>>sum;
    for(int i=1;i<=sum;i++){
        cin>>a[i];
    }
    for(int i=1;i<=sum;i++){
        for(int j=i+1;j<=sum;j++){
            for(int p=j+1;p<=sum;p++){
                if((a[i]+a[j]+a[p])>max(a[i],max(a[j],a[p])));
                    z++;
            }
        }
    }
    cout<<z%998%244%353;
    return 0;
}
