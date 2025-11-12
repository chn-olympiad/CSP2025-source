#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,s1={0,1,2,3,4,5,6,7,8,9};
    cin>>s;
    vector<int> b;
    int h=0;
    int a=s.size();
    for(int i=0;i<a;i++){
        for(int j=0;j<10;j++){
            if(s[i]==s1[j]){
                b[h]=j;
                h++;
            }
        }
    }
    int a1=b.size();
    int y[a1];
    for(int i=0;i<=a1;i++){
        y[i]=b[i];
    }
    sort(y,y+a1);
    for(int j=0;j<=a1;j++){
        cout<<y[j];
    }
    return 0;
}
