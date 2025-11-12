#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1001];
    cin >> s;
    int i=0;
    for(char c : s){
        if(c >= '0' && c <= '9'){
            a[i]=c-'0';
            i++;
        }
    }
    int k;
    for(int j=0;j<i;j++)
    {
        for(int n=i;n>j;n--)
        {
            if(a[n]>a[n-1])
            {
                k=a[n-1];
                a[n-1]=a[n];
                a[n]=k;
            }
        }
        cout<<a[j];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
