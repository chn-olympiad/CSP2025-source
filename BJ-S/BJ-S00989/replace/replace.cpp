#include<bits/stdc++.h>
using namespace std;
struct node{
    string s1,s2;
    string ts1,ts2;
    int l,r,dx,sl;
};
vector<node>a[1000006];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,cd,zcd,_l,_r,summ;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        string d1,ds1,xy,ds2;
        zcd=0;
        cin>>d1;
        cin>>xy;
        ds1="s";
        ds2="s";
        cd=d1.size();
        for(int j=0;j<cd;j++){
            if(d1[j]==xy[j]) zcd++;
            else{
                _l=j;
                break;
            }
        }
        for(int j=cd-1;j>_l;j--){
            if(d1[j]==xy[j]) zcd++;
            else{
                _r=j;
                break;
            }
        }

        zcd=cd-zcd;
        if(zcd!=0){
            for(int j=_l;j<=_r;j++){
                ds1+=d1[j];
                ds2+=xy[j];
            }
        }

        if(zcd==0) a[0].push_back({d1,xy,"a","b",_l,_r,cd,1});
        else a[zcd].push_back({d1,xy,ds1,ds2,_l,_r,cd,1});
    }
    while(q--){
        string d1,ds1,xy,ds2;
        int pos=-1;
        summ=0;
        zcd=0;
        ds1=ds2="s";
        cin>>d1;
        cin>>xy;
        if(d1.size()!=xy.size()){
            cout<<0<<endl;
            continue;
        }
        cd=d1.size();
        for(int j=0;j<cd;j++){
            if(d1[j]==xy[j]) zcd++;
            else{
                _l=j;
                //cout<<"*"<<j<<endl;
                break;
            }
        }
        for(int j=cd-1;j>_l;j--){
            if(d1[j]==xy[j]) zcd++;
            else{
                _r=j;
                //cout<<"*"<<j<<endl;
                break;
            }
        }
        zcd=cd-zcd;
        if(zcd!=0){
            for(int j=_l;j<=_r;j++){
                ds1+=d1[j];
                ds2+=xy[j];
            }
        }
        if(zcd==0){
            long long tot=0;
            for(int e=0;e<a[0].size();e++){
                tot+=(cd-a[0][e].dx+1);
            }
            cout<<tot<<endl;
            continue;
        }
        else{
            for(int e=a[zcd].size();e>=1;e--){
                if(a[zcd][e-1].ts1==ds1&&a[zcd][e-1].ts2==ds2){
                    summ++;
                    if(pos!=-1){
                        a[zcd][e-1].sl+=a[zcd][pos].sl;
                        pos=e-1;
                    }
                }
            }
            cout<<summ<<endl;
        }
        //cout<<"?"<<" "<<zcd<<" "<<ds1<<" "<<ds2<<endl;
        //cout<<"!"<<_l<<" "<<_r<<" "<<zcd<<endl;
    }
    return 0;

}
