#include <bits/stdc++.h>
using namespace std;
//string s;
int ma,su=0;
int n,a[5005],cou=0;
int ch(int x,int y){
    int d=y;
    for(int i=1;i<=x;i++){
        y*=d;
    }
    return y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    else if(n==3){
        int ma=max(a[1],max(a[2],a[3]));
        if(a[1]+a[2]+a[3]>2*ma) cout<<1;
        else cout<<0;
    }
    else if(n==4){
        int ma=max(a[1],max(a[2],a[3]));
        if(a[1]+a[2]+a[3]>2*ma) cou++;
        int ma=max(a[1],max(a[2],a[4]));
        if(a[1]+a[2]+a[4]>2*ma) cou++;
        int ma=max(a[1],max(a[4],a[3]));
        if(a[1]+a[4]+a[3]>2*ma) cou++;
        int ma=max(a[4],max(a[2],a[3]));
        if(a[4]+a[2]+a[3]>2*ma) cou++;
        int ma=max(max(a[1],a[4]),max(a[2],a[3]));
        if(a[1]+a[2]+a[3]+a[4]>2*ma) cou++;
        cout<<cou;
    }
    else if(n==5){#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cou=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cou++;
            a[cou]=s[i]-'0';
        }
    }
    sort(a+1,a+cou+1);
    for(int i=cou;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
            ma=0,su=0,cou=0;
            for(int i=1;i<=31;i++){
                for(int j=1;j<=5;j++){
                    if(i&(ch(j,2)/4) {ma=max(ma,a[j]);
                        su+=a[j];
                    }
                }
                if(su>2*ma) cou++;
            }

        /*int ma=max(a[1],max(a[2],a[3]));
        if(a[1]+a[2]+a[3]>2*ma) cou++;
        int ma=max(a[1],max(a[2],a[4]));
        if(a[1]+a[2]+a[4]>2*ma) cou++;
        int ma=max(a[1],max(a[4],a[3]));
        if(a[1]+a[4]+a[3]>2*ma) cou++;
        int ma=max(a[4],max(a[2],a[3]));
        if(a[4]+a[2]+a[3]>2*ma) cou++;
        int ma=max(max(a[1],a[4]),max(a[2],a[3]));
        if(a[1]+a[2]+a[3]+a[4]>2*ma) cou++;*/
        cout<<cou;
    }
    else{

    }
    return 0;
}
