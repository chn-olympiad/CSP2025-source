#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string st;
    int k=1;
    cin>>st;
    for(int i=0;i<st.size();i++){
        if(isdigit(st[i])){
            a[k]=int(st[i]-'0');
            k++;
        }
    }
    sort(a+1,a+k);
    for(int i=k-1;i>0;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
