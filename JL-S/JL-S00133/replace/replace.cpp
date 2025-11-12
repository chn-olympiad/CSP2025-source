#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
struct node{
    string a1,a2;
}a[N];
struct node2{
    string b1,b2;
}b[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].a1>>a[i].a2;
    }
    for(int i=1;i<=q;i++){
        int sum=0;
        cin>>b[i].b1>>b[i].b2;
        for(int j=1;j<=n;j++){
            if(a[j].a1==b[i].b1){
                if(a[j].a2==b[i].b2){
                    sum+=1;
                }
            }
            else{
                //qwq字符串搜索字符串忘了:-(
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
