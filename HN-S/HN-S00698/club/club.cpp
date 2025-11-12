#include<bits/stdc++.h>
using namespace std;
struct people{
    int a,b,c;
}s[100005];
bool cmpa(people g1,people g2){
    return (g1.a>g2.a)||(g1.a==g2.a&&g1.b>g2.b);
}
bool cmpb(people g1,people g2){
    return (g1.b>g2.b)||(g1.b==g2.b&&g1.a>g2.a);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,moden=0,ua=0,ub=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
            ua+=s[i].a;
            ub+=s[i].b;
        }

    if(s[1].c==0&&s[2].c==0&&s[3].c==0){
        moden=2;
        if(s[1].b==0&&s[2].b==0&&s[3].b==0){
            moden=1;
        }
        if(moden==1){
            sort(s+1,s+1+n,cmpa);
            int ans=0;
            for(int i=n;i>n/2;i--){
                ans+=s[i].a;
            }
        }else{
            int ans=0;
            if(ua>ub){
                sort(s+1,s+1+n,cmpa);
                for(int i=1;i<=n;i++){
                    if(i<=n/2){
                        ans+=s[i].a;
                    }else{
                        ans+=s[i].b;
                    }
                }
            }else{
                sort(s+1,s+1+n,cmpb);
                for(int i=1;i<=n;i++){
                    if(i<=n/2){
                        ans+=s[i].b;
                    }else{
                        ans+=s[i].a;
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
    }
    return 0;
}

