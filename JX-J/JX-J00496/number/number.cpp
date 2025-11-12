#include<bits/stdc++.h>
using namespace std;
string s;
int cmp(int x,int y){
    return x>y;
}
int arr[1005],n=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            n++;
            arr[n]=int(s[i]-48);
        }
    }
    sort(arr+1,arr+n+1,cmp);
    for(int i=1;i<=n;i++){
        cout<<arr[i];
    }
    return 0;
}
