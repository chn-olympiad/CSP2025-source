#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string a[200100][3],x,y;
bool check(int st,int tp){
    int leng=a[tp][1].length();
    for(int i=0;i<leng;i++){
        if(x[i+st]!=a[tp][1][i])return 0;
    }return 1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i][1]>>a[i][2];
    }for(int ii=0;ii<m;ii++){
        cin>>x>>y;ans=0;
        for(int i=0;i<x.length();i++){
            for(int j=0;j<n;j++){
                if(check(i,j)){
                    string k=x;int flag=0;
                    for(int o=0;o<a[j][1].length();o++){
                        k[i+o]=a[j][1][o];
                    }for(int o=0;o<x.length();o++){
                        if(k[i]!=y[i]){
                            flag=1;
                            break;
                        }
                    }if(!flag){
                        ans++;//for(int i=0;i<a[j][1].length();i++)cout<<a[j][1][i];cout<<endl;
                        //for(int o=0;o<x.length();o++){
                          //  cout<<k[o];
                        //}cout<<endl<<endl;
                    }
                }
            }
        }cout<<ans<<endl;
    }fclose(stdin);
    fclose(stdout);
}
