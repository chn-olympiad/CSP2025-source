#include<bits/stdc++.h>
using namespace std;
int T,n;
struct T{
    int a,b,c;
}x[50010],y[50010],z[50010];
/*bool cmp(T A,T B){
    if(A.a!=B.a)return A.a>B.a;
    if(A.b!=B.b)return A.b>B.b;
    if(A.c!=B.c)return A.c>B.c;
    return A.num>B.num;
}*/
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        bool flag=true;
        int ans=0,idxx=0,idxy=0,idxz=0,numx=0,numy=0,numz=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int A,B,C;
            scanf("%d %d %d",&A,&B,&C);
            if(C!=0)flag=false;
            int ma=max(A,max(B,C));
            if(ma==A){
                idxx++;
                numx++;
                if(numx<=n/2){
                    x[idxx].a=A;
                    x[idxx].b=B;
                    x[idxx].c=C;
                    ans+=A;
                }
                else{
                    numx--;
                    int sum=0,num;
                    for(int i=1;i<idxx;i++){
                        if(x[i].a==-1)continue;
                        if(max(x[i].b,x[i].c)+A-x[i].a>sum){
                            sum=max(x[i].b,x[i].c)+A-x[i].a;
                            num=i;
                        }
                    }
                    if(sum==0)ma=B;
                    else {
                        x[idxx].a=A;
                        x[idxx].b=B;
                        x[idxx].c=C;
                        ans+=sum;
                        if(x[num].b>x[num].c){
                            if(numy<n/2){
                                idxy++;
                                y[idxy].a=x[sum].a;
                                y[idxy].b=x[sum].b;
                                y[idxy].c=x[sum].c;
                                numy++;
                            }
                            else {
                                idxz++;
                                z[idxz].a=x[sum].a;
                                z[idxz].b=x[sum].b;
                                z[idxz].c=x[sum].c;
                                numz++;
                            }
                        }
                        else{
                            if(numz<n/2){
                                idxz++;
                                z[idxz].a=x[sum].a;
                                z[idxz].b=x[sum].b;
                                z[idxz].c=x[sum].c;
                                numz++;
                            }
                            else{
                                idxy++;
                                y[idxy].a=x[sum].a;
                                y[idxy].b=x[sum].b;
                                y[idxy].c=x[sum].c;
                                numy++;
                            }
                        }
                        x[num].a=-1;

                    }
                }
            }
            else if(ma==B){
                idxy++;
                numy++;
                if(numy<=n/2){
                    y[idxy].a=A;
                    y[idxy].b=B;
                    y[idxy].c=C;
                    ans+=B;
                }
                else{
                    numy--;
                    int sum=0,num;
                    for(int i=1;i<idxy;i++){
                        if(y[i].b==-1)continue;
                        if(max(y[i].a,y[i].c)+B-y[i].b>sum){
                            sum=max(y[i].a,y[i].c)+B-y[i].b;
                            num=i;
                        }
                    }
                    if(sum==0)ma=C;
                    else {
                        y[idxy].a=A;
                        y[idxy].b=B;
                        y[idxy].c=C;
                        ans+=sum;
                        if(y[num].a>y[num].c){
                            if(numx<n/2){
                                idxx++;
                                x[idxx].a=y[sum].a;
                                x[idxx].b=y[sum].b;
                                x[idxx].c=y[sum].c;
                                numx++;
                            }
                            else {
                                idxz++;
                                z[idxz].a=y[sum].a;
                                z[idxz].b=y[sum].b;
                                z[idxz].c=y[sum].c;
                                numz++;
                            }
                        }
                        else{
                           if(numz<n/2){
                                idxz++;
                                z[idxz].a=y[sum].a;
                                z[idxz].b=y[sum].b;
                                z[idxz].c=y[sum].c;
                                numz++;
                            }
                            else{
                                idxx++;
                                x[idxx].a=y[sum].a;
                                x[idxx].b=y[sum].b;
                                x[idxx].c=y[sum].c;
                                numx++;
                            }
                        }
                        y[num].b=-1;

                    }
                }
            }
            else{
                idxz++;
                numz++;
                if(numz<=n/2){
                    z[idxz].a=A;
                    z[idxz].b=B;
                    z[idxz].c=C;
                    ans+=C;
                }
                else{
                    numz--;
                    int sum=0,num;
                    for(int i=1;i<idxz;i++){
                        if(z[i].c==-1)continue;
                        if(max(z[i].a,z[i].b)+C-z[i].c>sum){
                            sum=max(z[i].a,z[i].b)+C-z[i].c;
                            num=i;
                        }
                    }

                        z[idxz].a=A;
                        z[idxz].b=B;
                        z[idxz].c=C;
                        ans+=sum;
                        if(z[num].b>z[num].a){
                            if(numy<n/2){
                                idxy++;
                                y[idxy].a=z[sum].a;
                                y[idxy].b=z[sum].b;
                                y[idxy].c=z[sum].c;
                                numy++;
                            }
                            else {
                                idxx++;
                                x[idxx].a=z[sum].a;
                                x[idxx].b=z[sum].b;
                                x[idxx].c=z[sum].c;
                                numx++;
                            }
                        }
                        else{
                            if(numx<n/2){
                                idxx++;
                                x[idxx].a=z[sum].a;
                                x[idxx].b=z[sum].b;
                                x[idxx].c=z[sum].c;
                                numx++;
                            }
                            else{
                                idxy++;
                                y[idxy].a=z[sum].a;
                                y[idxy].b=z[sum].b;
                                y[idxy].c=z[sum].c;
                                numy++;
                            }
                        }
                        z[num].c=-1;

                }
            }

        }/*
        for(int i=1;i<=idxx;i++)cout<<x[i].a<<" "<<x[i].b<<" "<<x[i].c<<endl;
        cout<<endl;
        for(int i=1;i<=idxy;i++)cout<<y[i].a<<" "<<y[i].b<<" "<<y[i].c<<endl;
        cout<<endl;
        for(int i=1;i<=idxz;i++)cout<<z[i].a<<" "<<z[i].b<<" "<<z[i].c<<endl;
        cout<<endl;*/
        printf("%d\n",ans);

    }
    return 0;
}
