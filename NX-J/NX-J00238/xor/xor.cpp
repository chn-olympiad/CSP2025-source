#include<bits/stdc++.h>
using namespace std;
struct qu{
    int start;
    int last;
};
bool cmp(qu a,qu b){
    return a.last<b.last;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    vector<int> v;
    vector<qu> v1;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int c;
        cin>>c;
        v.push_back(c);
    }
    int num;
    for(int i=0;i<v.size();i++){
        for(int j=i;j<v.size();j++){
            num=0;
            for(int k=i;k<=j;k++){
                num^=v[k];
            }
            if(num==k){
                qu c;
                c.start=i;
                c.last=j;
                v1.push_back(c);
            }
        }
    }
    sort(v1.begin(),v1.end(),cmp);
    int zuih=0,flag=1;
    num=0;
    for(int i=0;i<v1.size();i++){
        if(zuih<v1[i].start||zuih==0&&zuih<=v1[i].start&&flag){
            num++;
            zuih=v1[i].last;
            flag=0;
        }
    }
    cout<<num;
    return 0;
}
