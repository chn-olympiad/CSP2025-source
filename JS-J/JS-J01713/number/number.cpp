#include<bits/stdc++.h>
using namespace std;
void sort(int a[],int cnt){
    for(int i=1;i<=cnt;i++){
        for(int j=i;j<=cnt;j++)
            if(a[i]<a[j])
                swap(a[i],a[j]);
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char c;
    int a[1000005],cnt=0;
    while(cin>>c){
        if(c>='0' and c<='9')
            a[++cnt]=int(c-'0');
    }
    sort(a,cnt);
    for(int i=1;i<=cnt;i++)
        cout<<a[i];
    return 0;
}
