#include<bits/stdc++.h>
using namespace std;
int n,m,c[1005][1005],d,e[10005],f,g=0;
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    cin>>n>>m;
    d=n*m;
    for(int i=0;i<d;i++){
        cin>>e[i];
    }
    f=e[0];
    sort(e,e+d-1,greater<int>());
    for(int q=0;q<m;q++){
        for(int w=0;w<n;w++){
            c[w][q]=e[g];
            g++;
        }
        q++;
        for(int t=n-1;t>=0;t--){
            c[t][q]=e[g];
            g++;
        }
    }
    for(int y=0;y<n;y++){
        for(int u=0;u<m;u++){
            if(c[y][u]==f){
                cout<<u+1<<' '<<y+1;
            }
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
