#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+7;
string s;
long long cnt=0,cnt2=0,n,a[N],b[N],c[N];
int main(){
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(0<=s[i]-'0'&&s[i]-'0'<=9){
            a[cnt]=s[i]-'0';
            b[cnt]=1;
            cnt++;
        }
    }

    for(int i=0;i<cnt;i++){
        if(b[i]){
            c[cnt2]=a[i];
            cnt2++;
        }
    }

    sort(c,c+cnt2);

    if(c[cnt2-1]==0){
        cout<<0;
        return 0;
    }

    for(int i=cnt2-1;i>=0;i--)
        cout<<c[i];

    return 0;
}
