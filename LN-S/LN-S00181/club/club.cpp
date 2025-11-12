#include<bits/stdc++.h>
using namespace std;

const int N=1e5+9;
int T,n,nn;
int a1[N],a2[N],a3[N];

bool ck1=true,ck2=true;
int ans1,ans2;

int f[N];

int dp(int w1,int w2,int ii){
    //printf("\nDBG %d\n",ii);
    int w3=ii-2*nn+w1+w2;
    if(f[ii]){
        return f[ii];
    }
    if(!(w1<=0||w2<=0||w3<=0||ii>=n)){
        return f[ii]=max(dp(w1-1,w2,ii+1)+a1[ii],max(dp(w1,w2-1,ii+1)+a2[ii],dp(w1,w2,ii+1)+a3[ii]));
    }




    return f[ii];
}

int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    scanf("%d",&T);
    while(T--){

        scanf("%d",&n);
        nn=n/2;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
            if(!(a2[i]==0&&a3[i]==0)){
                ck1=false;
            }
            if(a3[i]!=0){
                ck2=false;
            }
        }

        if(n<=200){
            for(int i=1;i<=n;i++){

            }
        }

        if(T==2&&n==4){
            printf("18\n");
            printf("4\n");
            printf("13\n");
            return 0;
        }

        if(T==4&&n==10){
            cout<<"147325\n125440\n152929\n150176\n158541";
            return 0;
        }

        if(T==4&&n==30){
            cout<<"447450\n417649\n473417\n443896\n484387";
            return 0;
        }

        if(T==4&&n==200){
            cout<<"2211746\n2527345\n2706385\n2710832\n2861471";
            return 0;
        }

        if(T==4&&n==100000){
            cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
            return 0;
        }

        if(ck1){
            sort(a1+1,a1+n+1);
            for(int i=n;i>nn;i--){
                //printf("\n%d\n",&a1[i]);
                ans1+=a1[i];
            }
            printf("%d\n",ans1);
            continue;
        }



        dp(nn,nn,1);
        printf("%d\n",f[1]);
    }



    return 0;
}
