#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string arr[n][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<q;i++){
        string t[2];
        cin>>t[0]>>t[1];
        int res=0;
        int temple1=t[0].size();
        int temple;
        for(int a=0;a<n;a++){
            temple=arr[a][0].size();
            for(int b=0;b<temple1-temple+1;b++){
                if(t[0].substr(b,temple)==arr[a][0]){
                    if(b==0){
                        if(arr[a][1]+t[0].substr(b+1,temple1-temple)==t[1]){
                            res++;
                        }
                    }
                    else if(b==temple1-temple){
                        if(t[0].substr(0,temple1-temple)+arr[a][1]==t[1]){
                            res++;
                        }
                    }
                    else{
                        if(t[0].substr(0,b)+arr[a][1]+t[0].substr(b+temple,temple1-temple-b)==t[1]){
                            res++;
                        }
                    }
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
