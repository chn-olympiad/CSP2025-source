#include<bits/stdc++.h>
using namespace std;
int T;
struct mim{
    int c1;
    int c2;
    int poi;
    int no1;
    int no2;
    int num;
    short sor;
}mi[100005];
struct Pe{
    int n1;
    int n2;
    int n3;
}a [100005];
int n,fa[100005][4];
bool cmp(Pe nn,Pe mm){
    return nn.n1>mm.n1;
}
bool cmp2(mim x,mim y){
    return x.c1<y.c1;
}
bool cmp3(mim x,mim y){
    return x.sor>y.sor;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        long long ans=0;
        bool flag1=0,flag2=0;
        cin>>n;
        int tmp1=0,tmp2=0,tmp3=0;
        for(int i=1;i<=n;i++){
            mi[i].poi = i;
            cin>>a[i].n1>>a[i].n2>>a[i].n3;

            if(a[i].n1>a[i].n2){
                if(a[i].n1>a[i].n3){
                    fa[i][1] = 1;
                    if(a[i].n2>a[i].n3){
                        mi[i].c1 = a[i].n1-a[i].n2;
                        mi[i].no1 = a[i].n1;
                        mi[i].no2 = a[i].n2;
                        mi[i].num = 1;
                        fa[i][2] = 2;
                        fa[i][3] = 3;
                    }else{
                        mi[i].c1 = a[i].n1-a[i].n3;
                        mi[i].no1 = a[i].n1;
                        mi[i].no2 = a[i].n3;
                        mi[i].num = 1;
                        fa[i][3] = 2;
                        fa[i][2] = 3;
                    }
                }else{
                    mi[i].c1 = a[i].n3-a[i].n1;
                    mi[i].no1 = a[i].n3;
                    mi[i].no2 = a[i].n1;
                    mi[i].num = 3;
                    fa[i][1] = 3;
                    fa[i][2] = 1;
                    fa[i][3] = 2;
                }
            }else{
                if(a[i].n1>a[i].n3){
                    mi[i].c1 = a[i].n2-a[i].n1;
                    mi[i].no1 = a[i].n2;
                    mi[i].no2 = a[i].n1;
                    mi[i].num = 2;
                    fa[i][1] = 2;
                    fa[i][2] = 1;
                    fa[i][3] = 3;

                }else{
                    fa[i][3] = 1;
                    if(a[i].n2>a[i].n3){
                        mi[i].c1 = a[i].n2-a[i].n3;
                        mi[i].no1 = a[i].n2;
                        mi[i].no2 = a[i].n3;
                        mi[i].num = 2;
                        fa[i][1] = 2;
                        fa[i][2] = 3;
                    }else{
                        mi[i].c1 = a[i].n3-a[i].n2;
                        mi[i].no1 = a[i].n3;
                        mi[i].no2 = a[i].n2;
                        mi[i].num = 3;
                        fa[i][1] = 3;
                        fa[i][2] = 2;
                    }
                }
            }
            //cout<<mi[i].c1<<" "<<mi[i].c2<<" "<<mi[i].no1<<" "<<mi[i].no2<<endl;
            //cout<<fa[i][1]<<" "<<fa[i][2]<<" "<<fa[i][3]<<endl;
            if(fa[i][1] == 1){
                tmp1++;
            }else if(fa[i][1] == 2){
                tmp2++;
            }else{
                tmp3++;
            }
            if(a[i].n2!=0){
                flag1=1;
                if(a[i].n3!=0){
                    flag2=1;
                }
            }
        }
        //cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<endl;
        int k = n/2;
        if(tmp1<=k&&tmp2<=k&&tmp3<=k){
            for(int i=1;i<=n;i++){
                if(fa[i][1] == 1){
                    ans+=a[i].n1;
                }else if(fa[i][1] == 2){
                    ans += a[i].n2;
                }else{
                    ans+= a[i].n3;
                }

            }
            cout<<ans<<endl;
            continue;
        }
        if(!flag1){
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=k;i++){
                ans+=a[i].n1;
            }
            cout<<ans<<endl;
            continue;
        }
        int more =0;
        int kkk=0;
        if(tmp1>k){
            more = tmp1-k;
            kkk=1;
        }
        if(tmp2>k){
            more = tmp2-k;
            kkk=2;
        }
        if(tmp3>k){
            more = tmp3-k;
            kkk=3;
        }
        for(int i=1;i<=n;i++){
            if(mi[i].num == kkk){
                mi[i].sor = 1;
            }
        }
        sort(mi+1,mi+1+n,cmp3);
        sort(mi+1,mi+1+more+k,cmp2);
        for(int i=1;i<=more;i++){
            mi[i].c2=1;
        }
        //cout<<endl<<endl;
        for(int i=1;i<=n;i++){
            //cout<<mi[i].c1<<" "<<mi[i].c2<<" "<<mi[i].no1<<" "<<mi[i].no2<<endl;
            if(mi[i].c2){
                ans+=mi[i].no2;

            }else{
                ans+=mi[i].no1;
            }
            mi[i].sor=0;
            mi[i].c2 =0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
