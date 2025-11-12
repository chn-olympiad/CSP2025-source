#include<bits/stdc++.h>
using namespace std;
int aq[20005],ah[20005],bq[20005],bh[20005];
int main (){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    int flag=0;
    for(int i=1;i<=n;i++){
        string a,b;
        cin >> a >> b;
        int q=0,h=0,z=0,qq=0;
        for(int j=0;j<a.size();j++){
            if(a[j]=='a'){
                q++;

            }else{
                flag++; qq=q;
                z=j;
            }
        }
        aq[i]=qq;
        ah[i]=a.size()-z-1;
        cout << z << endl;
        q=0,h=0,z=0,qq=0;
        for(int j=0;j<b.size();j++){
            if(b[j]=='a'){
                q++;
            }else{
                flag++;
                z=j;qq=q;
            }
        }
        bq[i]=qq;
        bh[i]=b.size()-1-z;
        //cout << aq[i] << " " << ah[i] << " "<< bq[i] << " " << bh[i] << endl;
    }
    int ans=0;
    for(int j=1;j<=q;j++){
        string a,b;
        cin >> a  >> b;
        int ab,bb;
        for(int i=0;i<a.size();i++){
            if(a[i]=='b'){
                ab=i;
            }
        }
        for(int i=0;i<b.size();i++){
            if(b[i]=='b'){
                bb=i;
            }
        }
        if(aq[j]<=ab&&ah[j]<(a.size()-ab-1)){
            if(bq[j]<=bb&&bh[j]<(b.size()-bb-1)){
            ans++;
            }
        }cout << ans<< endl;
    }
    
    return 0;
}
