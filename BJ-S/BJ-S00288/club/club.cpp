#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>

using namespace std;
struct A{
    int stu;
    int score;
}a[100100];
struct B{
    int stu;
    int score;
}b[100100];
struct C{
    int stu;
    int score;
}c[100100];
bool cmp(A p,A q){
    return p.score>q.score;
}
bool cmp1(B p,B q){
    return p.score>q.score;
}
bool cmp2(C p,C q){
    return p.score>q.score;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n==2){
            int a1,b1,c1,a2,b2,c2;
            cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
            int q=a1+b2;
            int w=a1+c2;
            int e=b1+a2;
            int r=b1+c2;
            int t=c1+a2;
            int y=c1+b2;
            int ans=max(q,max(w,max(e,max(r,max(t,y)))));
            cout << ans <<"\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            a[i].stu=i;
            cin >>a[i].score;
            b[i].stu=i;
            cin >>b[i].score;
            c[i].stu=i;
            cin >>c[i].score;
        }
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp1);
        sort(c+1,c+n+1,cmp2);
        //int q1=0,q2=0,q3=0;
        int m[100100];
        for(int i=1;i<=n;i++){
            m[i]=-1;
        }
        for(int i=1;i<=n/2;i++){
            for(int j=1;j<=n;j++){
                if(a[i].stu==j) m[j]=max(m[j],a[i].score);
                if(b[i].stu==j) m[j]=max(m[j],b[i].score);
                if(c[i].stu==j) m[j]=max(m[j],c[i].score);
            }
        }
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(m[i]!=-1) sum+=m[i];
        }
        cout << sum<<"\n";
    }
    return 0;
}