#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+2;



struct info{

    int a,b,c;
};

bool cmp(info &x,info &y){

    return x.a>y.a;
}

int t;

int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;

    while(t--){
        int n , ans = 0;
        info p[MAX];
        cin>>n;

        for(int i = 1;i<=n;i++){

            cin>>p[i].a>>p[i].b>>p[i].c;
        }

        if(n == 2){
            
            int Ma1 = max(max(p[1].a,p[1].b),p[1].c);
            int Mi1 = min(min(p[1].a,p[1].b),p[1].c);
            int Ma2 = max(max(p[2].a,p[2].b),p[2].c);
            int Mi2 = min(min(p[2].a,p[2].b),p[2].c);

            

            if((p[1].a == Ma1 && p[2].a == Ma2) || (p[1].b == Ma1 && p[2].b == Ma2) || (p[1].c == Ma1 && p[2].c == Ma2)) {
                
                
                if(Ma1>Ma2){ 
                    ans += Ma1;
                    ans+= p[2].a+p[2].b+p[2].c - Ma2 - Mi2;
                }
                else{
                    ans += Ma2;
                    ans+= p[1].a+p[1].b+p[1].c - Ma1-Mi1;
                }
            }
            else{

                ans = Ma1+Ma2;
            }
            
        }

        else if(p[1].b == 0 && p[2].c == 0){

            sort(p+1,p+1+n,cmp);
            
            for(int i = 1;i<=n/2;i++){
                ans+=p[i].a;
            }

        }



        cout<<ans<<'\n';

    }

    fclose(stdin);
    fclose(stdout);


    return 0;
}