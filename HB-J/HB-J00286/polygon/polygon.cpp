#include<bits/stdc++.h>
using namespace std;
const int mx=22;
//const int mod=998244353;
int a[mx],n,ans,i[22],cnt,k,mxn;
set<string> s;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i21=1;i21<=n;i21++){
        cin>>a[i21];
    }
    for(i[1]=0;i[1]<=1;i[1]++){

    for(i[2]=0;i[2]<=1;i[2]++){

    for(i[3]=0;i[3]<=1;i[3]++){

    for(i[4]=0;i[4]<=1;i[4]++){

    for(i[5]=0;i[5]<=1;i[5]++){

    for(i[6]=0;i[6]<=1;i[6]++){

    for(i[7]=0;i[7]<=1;i[7]++){

    for(i[8]=0;i[8]<=1;i[8]++){

    for(i[9]=0;i[9]<=1;i[9]++){

    for(i[10]=0;i[10]<=1;i[10]++){

    for(i[11]=0;i[11]<=1;i[11]++){

    for(i[12]=0;i[12]<=1;i[12]++){

    for(i[13]=0;i[13]<=1;i[13]++){

    for(i[14]=0;i[14]<=1;i[14]++){

    for(i[15]=0;i[15]<=1;i[15]++){

    for(i[16]=0;i[16]<=1;i[16]++){

    for(i[17]=0;i[17]<=1;i[17]++){

    for(i[18]=0;i[18]<=1;i[18]++){

    for(i[19]=0;i[19]<=1;i[19]++){

    for(i[20]=0;i[20]<=1;i[20]++){
        cnt=k=mxn=0;
        for(int i21=1;i21<=n;i21++){
            if(i[i21]!=0){
                cnt++;
            }
        }
        if(cnt<3){
            continue;
        }
        int l=s.size();
        string s1="";
        for(int i21=1;i21<=n;i21++){
            s1=s1+char(i[i21]);
        }
        s.insert(s1);
        if(s.size()==l) continue;
        for(int i21=1;i21<=n;i21++){
            if(i[i21]){
                k+=a[i21];
                mxn=max(a[i21],mxn);
            }
        }
        //cout<<s1<<":"<<k<<" "<<mxn;
        if(k>mxn+mxn){
            ans++;
            //cout<<s1;
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    cout<<ans;
    return 0;
}
