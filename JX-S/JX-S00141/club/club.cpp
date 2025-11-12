#include<bits/stdc++.h>
using namespace std;

struct A{
    int f;
    int g;
}ls[5]={0};


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t=0,n;
    cin>>t;
    while(t--){
        cin>>n;

        vector<int> a;
        vector<int> b;
        vector<int> c;
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                ls[i].f=i;
            }
            sort(ls+1,ls+4);

            if(ls[1].g==1&&a.size()<=n/2){
                a.push_back(ls[1].f);
            }
            else{
            if(ls[2].g==2&&b.size()<=n/2){
                a.push_back(ls[3].f);
            }else{
                c.push_back(ls[2].f);
            }
            if(ls[3].g==3&&b.size()<=n/2){
                c.push_back(ls[2].f);
            }else{
                b.push_back(ls[3].f);
            }
            }
        }
        int len1=a.size();
        int len2=b.size();
        int len3=c.size();
        int sum=0;
        for(int i=0;i<len1;i++){
            sum+=a[i];
        }
        for(int i=0;i<len2;i++){
            sum+=b[i];
        }
        for(int i=0;i<len3;i++){
            sum+=c[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
