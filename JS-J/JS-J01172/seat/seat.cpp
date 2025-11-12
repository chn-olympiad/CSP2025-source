#include<bits/stdc++.h>
using namespace std;
struct st{
    int a;
    int id;
};
bool cmp(st a,st b){
    return a.a>b.a;
}
st s[100+10];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,idx=0;
    cin>>n>>m;
    int num=n*m;
    for(int i=0;i<num;i++){
        cin>>s[i].a;
        s[i].id=i;
    }
    sort(s,s+num,cmp);
    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                if(s[idx].id==0){
                    cout<<i+1<<' '<<j+1<<endl;
                    return 0;
                }
                else idx++;
            }
        }
        if(i%2==1){
            for(int j=n-1;j>=0;j--){
                if(s[idx].id==0){
                    cout<<i+1<<' '<<n-j+1<<endl;
                    return 0;
                }
                else idx++;
            }
        }
    }
    
    
    return 0;
}