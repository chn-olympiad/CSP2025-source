#include<iostream>
#include<cstdio>
using namespace std;
int n,k,cnt,sum=-1;
int a[500000];
int main(){
        freopen("xor.in","r",stdin);
        freopen("xor.out","w",stdout);
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(sum==-1) sum=a[i];
            else sum^=a[i];
            if(sum==k){
                cnt++;
                sum=-1;
            }
        }
        cout<<cnt;
        fclose(stdin);
        fclose(stdout);
        return 0;
}
