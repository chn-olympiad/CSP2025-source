#include<bits/stdc++.h>
using namespace std;
bool cmp(int q,int q2){
    return q>q2;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string r;
    char n[100005];
    int y=0;
    cin>>r;
    for(int i=0;i<r.length();i++){
        if(isdigit(r[i])){
            n[y]=r[i];
            y++;
        }
    }
    sort(n,n+y,cmp);

    for(int i=0;i<y;i++){
        cout<<n[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
