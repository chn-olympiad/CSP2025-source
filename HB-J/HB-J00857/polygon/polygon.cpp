#include<bits/stdc++.h>
using namespace std;
int n;
int a[15];
bool fa[3628900][15];
bool ji[15];
int fl=1;
void quan(int nw,int ge){
            if(nw>=ge){
                        for(int i=1;i<=ge;i++){
                                    fa[fl][i]=ji[i];
                                    fl++;
                        }
                        memset(ji,0,sizeof(ji));
                        return ;
            }
            else {
                        for(int i=1;i<=n;i++){
                                    ji[nw]=i;
                                    quan(nw++,ge);
                        }
            }
            return ;
}
int main(){
      freopen("polygon.in","r",stdin);
      freopen("polygon.out","w",stdout);
      ios::sync_with_stdio(0);
      cin.tie(0);cout.tie(0);
      cin>>n;
      for(int i=0;i<n;i++){
            cin>>a[i];
      }
      if(n==3){
                  sort(a,a+n);
                  if(a[0]+a[1]>a[2]){
                              cout<<"1"<<endl;
                  }else{
                              cout<<"0"<<endl;
                  }
      }
      return 0;
}
