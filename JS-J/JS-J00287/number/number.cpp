#include<bits/stdc++.h>
using namespace std;
string str;
const int N=1e6+5;
int lst[N],k=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    for(int i=0;i<str.size();i++){
        char a=str[i];
        if(a-'0'>=0&&a-'0'<=9){
            k++;
            lst[k]=a-'0';
        }
    }
    sort(lst+1,lst+1+k);
    for(int i=k;i>=1;i--){
        cout<<lst[i];
    }
    return 0;
}
