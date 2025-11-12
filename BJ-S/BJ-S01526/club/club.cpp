#include<bits/stdc++.h>
using namespace std;
struct aaa{
    int xyz,w;
};
struct sb{
    aaa a[3];
};
sb a[100005];
bool aa(aaa a1,aaa a2){
    return a1.w>a2.w;
}
bool cnm(sb sb1,sb sb2){
    if(sb1.a[0].w-sb1.a[1].w!=sb2.a[0].w-sb2.a[1].w)
    return sb1.a[0].w-sb1.a[1].w>sb2.a[0].w-sb2.a[1].w;
    return sb1.a[0].w-sb1.a[2].w>sb2.a[0].w-sb2.a[2].w;
}

int main(){
    int t;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        int bbb[3]={};
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a[0].w>>a[i].a[1].w>>a[i].a[2].w;
            a[i].a[0].xyz=0;
            a[i].a[1].xyz=1;
            a[i].a[2].xyz=2;
            sort(a[i].a,a[i].a+3,aa);
        }
        sort(a+1,a+1+n,cnm);
        int ans=0;
        for(int i=1;i<=n;i++){
            sb s=a[i];
            for(int j=0;j<3;j++){
                aaa chaos=s.a[j];
                if(bbb[chaos.xyz]*2<n){
                    ans+=chaos.w;
                    bbb[chaos.xyz]++;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
