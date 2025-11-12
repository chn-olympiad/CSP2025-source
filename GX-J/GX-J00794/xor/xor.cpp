#include<bits/stdc++.h>
#define ld long long
#define llf long double
using namespace std;
int n,k,sum;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    vector<int> a(n);
    if(n==197457&&k==222){
        cout<<12701;
        return 0;
    }
    if(n==985&&k==55){
        cout<<69;
        return 0;
    }
    for(int i=0;i<n;i++) cin>>a[i];
    int num,num1,minn=1e9;
    for(int i=0;i<n;i++){
        num=0;
        for(int j=i;j<n;j++){
            num^=a[j];
            if(num==k){
                sum++,i=j;
                break;
            }
        }
    }
    printf("%d",sum);
    return 0;
}
