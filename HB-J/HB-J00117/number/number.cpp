#include<bits/stdc++.h>
using namespace std;
string s;
int arr[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int a=s.size(),b=1;
    for(int i=0;i<a;i++){
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
            arr[i]=s[i]-'0',b++;
    }
    sort(arr,arr+b);
    for(int i=b-1;i>0;i--)
        cout<<arr[i];

    return 0;
}
