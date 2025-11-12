#include<bits/stdc++.h>
using namespace std;
int t;int d[4][2];
short cmp(int p,int q,int r){
    if(p>=q){
        if(p>=r){
            return 1;
        }
        else{
            return 3;
        }
    }
    else{
        if(q>=r){
            return 2;
        }
        else{
            return 3;
        }
    }
}
int max3(int p,int q,int r){
    return max(max(p,q),r);
}

struct stu{
    int p=0,q=0,r=0;
    short n;
    void gt(){
        cin>>this->p>>this->q>>this->r;
    }
    void sii(){
        n=cmp(this->p,this->q,this->r);
        d[cmp(this->p,this->q,this->r)][0]+=max3(this->p,this->q,this->r);
        d[cmp(this->p,this->q,this->r)][1]+=1;
    }
    void ccm(stu a){
        this->p=a.p;
        this->q=a.q;
        this->r=a.r;
        return ;
    }
    int p1(){
        return this->p-max(this->q,this->r);
    }
    int q1(){
        return this->q-max(this->p,this->r);
    }
    int r1(){
        return this->r-max(this->p,this->q);
    }
};
stu aa[100005];
bool cmpp(stu a,stu b){
    return a.p1()<b.p1();
}
bool cmpq(stu a,stu b){
    return a.q1()<b.q1();
}
bool cmpr(stu a,stu b){
    return a.r1()<b.r1();
}

int main()
{
    freopen("club1.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {   stu m[4][100005]={0};
        for(int i=0;i<4;i++){
            for(int j=0;j<2;j++){
                d[i][j]=0;
            }

        }
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            aa[i].gt();
            aa[i].sii();
            m[aa[i].n][n].ccm(aa[i]);
        }
        int t=max3(d[1][1],d[2][1],d[3][1]);
        int sum=d[1][0]+d[2][0]+d[3][0];
        if(t>=n/2){
            int a=cmp(d[1][1],d[2][1],d[3][1]);
            if(a==1){
                sort(m[a]+1,m[a]+n+1,cmpp);
                for(int i=1;i<=t-(n/2);i++)sum-=m[a][i].p1();
            }
            if(a==2){
                sort(m[a]+1,m[a]+n+1,cmpq);
                for(int i=1;i<=t-(n/2);i++)sum-=m[a][i].q1();
            }
            if(a==3){
                sort(m[a]+1,m[a]+n+1,cmpr);
                for(int i=1;i<=t-(n/2);i++)sum-=m[a][i].r1();
            }
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
