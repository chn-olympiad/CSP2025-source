#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,q;
int ha[1000100][3];
int hlength[1000100];

int pow112(int a,int b){
    int ret=1;
    int s=a;
    while(b>0){
        if(b%2==1){
            ret*=s;
        }
        s*=s;
        s%=9982443;
        ret%=9982443;
        b/=2;
    }
    return ret;
}

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin >> n >> q;
    for(int i=1;i<=n;i++){
        string s1;
        string s2;
        cin >> s1 >> s2;
        hlength[i]=s1.length();
        for(int j=0;j<s1.length();j++){
            ha[i][1]*=26;
            ha[i][1]+=(s1[j]-'a');
            ha[i][1]%=9982443;
        }
        for(int j=0;j<s2.length();j++){
            ha[i][2]*=26;
            ha[i][2]+=(s2[j]-'a');
            ha[i][2]%=9982443;
        }
    }
    /*for(int i=1;i<=n;i++){
        cout << ha[i][1] << " " << ha[i][2] <<endl;
    }*/
    for(int i=1;i<=q;i++){
        string t1;
        string t2;
        int h1=0;
        int h2=0;
        cin >> t1 >> t2;
        if(t1.length()!=t2.length()){
            cout << 0 <<endl;
            continue;
        }
        for(int j=0;j<t1.length();j++){
            h1*=26;
            h1+=(t1[j]-'a');
            h1%=9982443;
        }
        for(int j=0;j<t2.length();j++){
            h2*=26;
            h2+=(t2[j]-'a');
            h2%=9982443;
        }
        //cout <<h1 <<" " <<h2 <<endl;
        int ans=0;
        for(int j=1;j<=n;j++){
            if(hlength[j]>t1.length()){
                continue;
            }
            int pow1=1;
            int hal=0;
            for(int k=0;k<hlength[j];k++){
                hal*=26;
                hal+=(t1[k]-'a');
                hal%=9982443;
                pow1*=26;
                pow1%=9982443;
            }
            //cout << pow1 << endl;
            for(int k=hlength[j]-1;k<t1.length();k++){
                if(hal==ha[j][1]){
                    //cout << '(' << ((h1+9982443)-(hal*pow112(26,t1.length()-k-1)%9982443)+(ha[j][2]*pow112(26,t1.length()-k-1)%9982443))%9982443 << ')' << endl;
                    if(((h1+9982443)-(hal*pow112(26,t1.length()-k-1)%9982443)+(ha[j][2]*pow112(26,t1.length()-k-1)%9982443))%9982443==h2){
                        ans++;
                    }
                }
                if(k!=t1.length()-1){
                    hal*=26;
                    hal+=(t1[k+1]-'a');
                    hal%=9982443;
                    hal-=pow1*(t1[k+1-hlength[j]]-'a');
                    hal+=9982443*26;
                    hal%=9982443;
                }
                //cout << hal << endl;
            }
            //cout << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
