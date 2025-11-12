#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+15;
string a;
int sum[100]={};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.length();++i){
        if(a[i]=='1' || a[i]=='2' || a[i]=='3' || a[i]=='4' || a[i]=='5' || a[i]=='6' || a[i]=='7' || a[i]=='8' || a[i]=='9' || a[i]=='0'){
            int f=int(a[i]-'0');
            sum[f]++;
        }
    }
    for(int k=9;k>=0;--k){
        for(int j=1;j<=sum[k];++j){
            cout<<k;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
