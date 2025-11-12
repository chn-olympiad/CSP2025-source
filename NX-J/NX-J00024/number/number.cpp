#include<bits/stdc++.h>
using namespace std;

const int KmaxN=1e6+1;

string s;

long long a[10],maxn,n;

bool isnum(char c){
    if(c<='9' && c>='0'){
        return true;
    }
    else return false;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //ios:sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    n=s.size();
    //cout<<n<<endl;
    for(int i=0;i<n;i++){
        if(isnum(s[i])){
            a[s[i]-'0']++;
            if((s[i]-'0')>maxn){
                maxn=s[i]-'0';
            }
        }
    }
    /*for(int i=0;i<10;i++){
        cout<<"i="<<i<<",a[i]="<<a[i]<<endl;
    }*/
    if(maxn==0){
        cout<<0<<endl;
        return 0;
    }
    for(int i=maxn;i>=0;i--){
        for(;a[i]>0;a[i]--){
            cout<<i;
        }
    }
    return 0;
}
