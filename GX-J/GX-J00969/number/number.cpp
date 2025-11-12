#include<iostream>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    char c[10]={'0','1','2','3','4','5','6','7','8','9'};
    cin>>a;
    int b[100],sy=0;
    for(int i=0;i<a.length();i++){
        for(int y=0;y<10;y++){
            if(a[i]==c[y]){
                b[sy]=y;
                sy++;
            }
        }
    }
    for(int i=9;i>=0;i--){
        for(int y=0;y<sy;y++){
            if(b[y]==i){
                cout<<b[y];
            }
        }
    }
    return 0;
}
