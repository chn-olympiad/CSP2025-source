#include<bits/stdc++.h>
using namespace std;
struct ma{
    int a1;
    int b1;
    int c1;
};
bool compare(const ma&a,const ma&b){
    if(a.a1!=b.a1){
        return a.a1>b.a1;
    }
    else if(a.b1!=b.b1){
        return a.b1>b.b1;
    }
    else if(a.c1!=b.c1){
        return a.c1>b.c1;
    }
}
const int N=1E6;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,num=0;
    cin>>n;
    ma a[N];
    for(int i=0;i<n;i++){
        cin>>a[i].a1;
        cin>>a[i].b1;
        cin>>a[i].c1;
    }
    sort(a,a+n,compare);
    for(int i=0;i<n;i++){
        num=a[i].a1+a[i].b1+a[i].c1;
    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
