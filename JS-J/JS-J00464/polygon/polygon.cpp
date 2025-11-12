#include<bits/stdc++.h>
using namespace std;
int n;
int a[5003];
int ANS;

int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    }
    sort (a+1,a+n+1);
    if(n==3){
        if(a[3]>=a[1]+a[2]){
        cout<<0<<endl;
        }
        else {
        cout<<1<<endl;
        }
        return 0;
    }
    for(int i=n;i>=3;i--){
        int maxn=a[i];
        for(int j=1;j<i;j++){
            for(int k=j+1;k<i;k++){
                int sum=0;
                for(int p=j;p<=k;p++){sum+=a[p];}
               if(sum>maxn&&k-j>=1){
                    ANS++;
                }
            }

        }
    }
    cout<<ANS*3/2<<endl;
    return 0;
}
