#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    int a,b,c=0,lie=0,hang=0;
    cin>>a>>b;
    int s[a*b+1]={0};
    for(int i=0;i<a*b;i++){
        cin>>s[i];
    }c=s[0];
    sort(s,s+a+b,cmp);
    for(int i=0;i<a*b;i++){
        if(c==s[i]){
            int d=i+1;
            if(d>a){
                lie=int(d/a)+1;
                if(d-(lie-1)*b>=0){
                    hang=d-(lie-1)*b+1;
                }else{
                    hang=(lie-1)*b-d;
                }
                if(hang==0)hang=b;
                cout<<lie<<" "<<hang;
                return 0;
            }if(d<=a){
                cout<<"1"<<" "<<d;
                return 0;
            }
        }
    }
    return 0;
}
