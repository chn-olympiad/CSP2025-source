#include <bits/stdc++.h>
using namespace std;
string s;
long long number[100000100];
bool cmp(int x,int y){
    return x>=y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long j=1;
    for (long long i=0;i<=s.size();i++){
        if (s[i]>='0' && s[i]<='9'){
            number[j] = s[i]-='0';
            j++;
        }
    }
    sort(number+1,number+j+1,cmp);
    if (number[1]==0){
        cout<<0;
    }
    else {
        for (long long i=1;i<j;i++){
            cout<<number[i];
        }
    }
    return 0;
}
