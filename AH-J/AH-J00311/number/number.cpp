#include<bits/stdc++.h>
using namespace std;
long long b[10000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    //cout<<a;
    int s=a.size();
    if(s==1){
        cout<<a;
        return 0;
    }
    //cout<<s;
    int sum=0;
    int p=0;
    for(int i=0;i<s;i++){
        if(a[i]=='1' or a[i]=='2' or a[i]=='3' or a[i]=='4' or a[i]=='5' or a[i]=='6' or a[i]=='7' or a[i]=='8' or a[i]=='9' ){
               //cout<<a[i]<<endl;
               sum=a[i]-'0';
               //cout<<sum<<endl;
               b[i]=sum;
               //cout<<b[i];
               p++;
        }
    }
    //cout<<p;
    int k=0;

    for(int i=0;i<p;i++){
        if(b[i]<b[i+1]){//3 5,k=3
            swap(b[i],b[i+1]);
        }
    }
    for(int i=0;i<p;i++){
        cout<<b[i];
    }
    return 0;
}
