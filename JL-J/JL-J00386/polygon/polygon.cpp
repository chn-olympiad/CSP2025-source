#include<bits/stdc++.h>
using namespace std;
int a,b,c=3,f,g,h;
vector <int> d;
vector <int> y;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>d[i];
    }
    b=d.size();
    for(int i=0;i<b;i++){
        d[i]=d[b-1];
        c++;
        for(int q=0;q<c;q++){
            y[q]=d[q];
        }
        sort(y,y+c-1,greater<int>());
        for(int r=0;r<(y.size());r++){
            g+=y[r];
        }
        if(g>y[0]*2){
            h++;
        }
    }
    cout<<h;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
