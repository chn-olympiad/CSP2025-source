#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >>n>>m>>k;
    while(n>0){
            for(int i;i<=m;i++){
                    for(int j;j<=k;j++){
                        for(int w=0;w<=m;w++){
                            for(int c=0;c<=k;c++){
                               for(int a=0;a<=j;a++){
                                    if(m==0||k==0||j==0){
                                        cout<<0;
                                    }
                                    else{
                                        cout<<w+c+a;
                                    }
                                    break;

                        }
                    }
                }
            }

        }

    }
    return 0;

}
