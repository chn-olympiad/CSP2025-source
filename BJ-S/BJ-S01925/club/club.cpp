#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[100010],b[100010],c[100010],x[100010];
int main(){
    int t,n,cnt=0;cnt1=0,cnt2=0,cnt3=0;
    cin>>t;
    for(int k=1;k<=t;k++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            x[i]=max(max(a[i],b[i]),c[i]);
        }
        sort(x+1,x+n+1);
        for(int i=n;i>=1;i--){
            if(x[i]==a[i]&&cnt1<=n/2){
                cnt1++;
                cnt+=x[i];
            }
            else if(x[i]==b[i]&&cnt2<=n/2){
                cnt2++;
                cnt+=x[i];
            }
            else if(x[i]==c[i]&&cnt3<=n/2){
                cnt3++;
                cnt+=x[i];
            }
        }
        cout<<cnt<<endl;
    }
}
