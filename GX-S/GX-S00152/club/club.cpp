#include<bits/stdc++.h>
using namespace std;
int t;
long long ans=0;
struct stu
{
    int a1,a2,a3;
    int position;
};
stu a[100005];
bool cmp1(const stu &b,const stu &c)
{
    if((b.a2-b.a3)>(c.a2-c.a3)){
        return 1;
    }
    return 0;
}
bool cmp2(const stu &b,const stu &c)
{
    int temp1;
    int temp2;
    if(b.position==2){
        temp1=b.a1-b.a2;
    }
    else{
        temp1=b.a1-b.a3;
    }
    if(c.position==2){
        temp2=c.a1-c.a2;
    }
    else{
        temp2=c.a1-c.a3;
    }
    if(temp1>temp2){
        return 1;
    }
    return 0;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    int n;
    for(int i=1;i<=t;i++){
        cin>>n;
        ans=0;
        for(int j=1;j<=n;j++){
            cin>>a[j].a1>>a[j].a2>>a[j].a3;
            ans+=a[j].a3;
            a[j].position=3;
        }
        int move1=0;
        sort(a+1,a+n+1,cmp1);
        for(int j=1;j<=n;j++){
            if(move1==n/2) break;
            ans+=a[j].a2-a[j].a3;
            a[j].position=2;
            move1++;
        }
        int move2=0;
        sort(a+1,a+n+1,cmp2);
        for(int j=1;j<=n;j++){
            if(move2==n/2) break;
            if(a[j].position==2){
                if(a[j].a1-a[j].a2>0){
                    ans+=a[j].a1-a[j].a2;
                    move2++;
                }
            }
            else{
                if(a[j].a1-a[j].a3>0){
                    ans+=a[j].a1-a[j].a3;
                    move2++;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
