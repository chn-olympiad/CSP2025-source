#include <bits/stdc++.h>
using namespace std;
long long N=10000006;
bool cmp(long long x,long long y){
    bool flag=1;
    if(x>=y){
        flag=0;
    }
    if(flag==1){
        return x<y;
    }
    else{
        return x>=y;
    }
}
int main( ){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    long long a[N]={ };
    long long ans=0;
    string s;
    cin>>s;
    long long sum=0;
    for(long long i=0;i<s.size();i++){
        if(s[i]>='1'&&s[i]<='9'){
            ans++;
            a[ans]= s[i]*1;
        }
    }
    sort(a+1,a+N+1,cmp);
    for(long long i=1;i<=ans;i++){
        sum+=10*i*a[i];
    }
    cout<<sum;
    return 0;
}

//#Shang4Shan3Ruo6Shui4
