#include<bits/stdc++.h>
using namespace std;
string a;
int t[15],k;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,a);
    k=a.size();
    for(int i=0;i<k;i++)
        if(a[i]>='0' && a[i]<='9')
            t[a[i]-'0']++;
    for(int i=9;i>=0;i--)
        while(t[i]){
            printf("%d",i);
            t[i]--;
        }
    printf("\n");
    return 0;
}
