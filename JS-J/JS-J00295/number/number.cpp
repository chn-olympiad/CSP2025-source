#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt]=s[i]-48;
            cnt++;
        }
    }
    for(int i=0;i<=cnt;i++){
        for(int j=0;j<=cnt;j++){
            if(a[j]<a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    int t=0,m=cnt;
    int i=0;
    while(m!=0){
        int b=1;
        for(int i=1;i<m;i++){
            b*=10;
        }
        if(a[i]==0) t*b;
        else        t+=a[i]*b;
        m--;
        i++;
    }
    cout<<t<<endl;
    return 0;
}
