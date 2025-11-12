#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=5e6+5;
int s[N],c[N];
int id[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)id[i]=i;
    for(int i=1;i<=n;i++){
        char ch;cin>>ch;
        s[i]=ch-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int ans=0;
    do{
        int res=0;
        int count=0;
        for(int i=1;i<=n;i++){
            // cout<<id[i]<<" ";
            int x=id[i];
            if(c[x]<=count){
                count++;
            }else{
                if(s[i]){
                    res++;
                }else{
                    count++;
                }
            }
        }
        // cout<<endl;
        // if(res>=m)cout<<"OK\n";
        ans+=res>=m;
    }while(next_permutation(id+1,id+1+n));
    cout<<ans<<endl;
    return 0;
}