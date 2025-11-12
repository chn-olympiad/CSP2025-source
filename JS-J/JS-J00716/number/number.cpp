#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1000001],cnt=1;
    cin>>s;
    int l=s.length();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt]=s[i]-'0';
            cnt++;
        }
    }
    sort(a,a+cnt);
    for(int i=cnt-1;i>=1;i--){
        cout<<a[i];
    }
}
  /*
RR RRRRRRRR         PPPPPPPPP             +                  +
RRRR      RRR       PP       PP           +                  +
RR          RR      PP        PP          +                  +
RR                  PP       PP     +++++++++++++      +++++++++++++
RR                  PPPPPPPPP             +                  +
RR                  PP                    +                  +
RR                  PP                    +                  +
RR                  PP                    +                  +*/
