#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    vector<int> v;
    int h,l;
    cin>>h>>l;
    int r;
    cin>>r;
    v.push_back(r);
    for(int i=2;i<=h*l;i++){
        int c;
        cin>>c;
        v.push_back(c);
    }
    sort(v.begin(),v.end(),cmp);
    int fang=1,mh=1,ml=1;
    for(int i=0;i<v.size();i++){
        if(v[i]==r){
            cout<<ml<<" "<<mh<<endl;
            return 0;
        }
        if(mh==1&&fang==0){
            ml++;
            fang=1;
            continue;
        }else if(mh==h&&fang==1){
            ml++;
            fang=0;
            continue;
        }
        if(fang){
            mh++;
        }else{
            mh--;
        }
    }
    return 0;
}
