#include<bits/stdc++.h>
using namespace std;
int t,n,s,ai[3];
struct stu{
    int a,b,c;
    int M(){
        return max(a,max(b,c));
    }
    int C(){
        return M()*2+L()-a-b-c;
    }
    int L(){
        return min(a,min(b,c));
    }
    int W(){
        if(M()==a){
            return 1;
        }
        if(M()==b){
            return 2;
        }
        if(M()==c){
            return 3;
        }
    }
    int W2(){
        if(C()==a){
            return 1;
        }
        if(C()==b){
            return 2;
        }
        if(C()==c){
            return 3;
        }
    }
};
bool cmp1(stu x,stu y){
    if(x.W()==y.W()){
        if(x.M()==y.M()){
            return x.C()>y.C();
        }
        else{
            return x.M()<x.M();
        }
    }
    else{
        return x.W()<y.W();
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int o=0;o<t;o++){
        cin>>n;
        stu c[n];
        int p=n/2;
        for(int i=1;i<=n;i++){
            cin>>c[i].a>>c[i].b>>c[i].c;
        }
        sort(c+1,c+n+1,cmp1);
        for(int i=1;i<=p;i++){
            s+=c[i].M();
            ai[c[i].W()]++;
        }
        for(int i=p+1;i<=n;i++){
            if(ai[c[i].W()]<p){
                s+=c[i].M();
                ai[c[i].W()]++;
            }
            else if(ai[c[i].W()]>=p){
                s+=c[i].C();
                ai[c[i].W2()]++;
            }
            else{
                s+=c[i].L();
                ai[6-c[i].W()-c[i].W2()];
            }
        }
        cout<<s<<endl;
        s=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
