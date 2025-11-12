#include<bits/stdc++.h>
using namespace std;

struct stu{
    int m1,m2,m3;
    bool a;
    int num;

}p[100005];



int main(){
    freopen("club.in","r",stdin);
    freopen("club,out","w",stdout);
    long long n,t;
    cin>>t;
    while(t--){
        cin>>n;
        long long ans=0;
        for(int i=1;i<=n;i++){
            cin>>p[i].m1>>p[i].m2>>p[i].m3;
            p[i].a=false;
        }
        for(int i=1;i<=n;i++){
            int love=max(max(p[i].m1,p[i].m2),p[i].m3);
            if(!p[i].a){
                if(love==p[i].m1){
                    p[1].num++;
                    ans+=love;
                    p[i].a=true;
                }
                if(love==p[i].m2){
                    p[2].num++;
                    ans+=love;
                    p[i].a=true;
                }
                if(love==p[i].m3){
                    p[3].num++;
                    ans+=love;
                    p[i].a=true;
                }
            }
        }
        if(p[1].num<=n/2 && p[2].num<=n/2&&p[3].num<=n/2){
            cout<<ans<<endl;
        }else{
            int
        }

    }
    return 0;
}
