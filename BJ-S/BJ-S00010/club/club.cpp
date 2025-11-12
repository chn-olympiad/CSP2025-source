#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int K=122222;
short t;
long long n,sum[5],ans;
struct stu{
    long long a1,a2,a3,k;
    void in(){
        cin>>a1>>a2>>a3;
        if((a1>=a2)&&(a1>=a3))k=1,sum[1]++;
        else if((a2>=a1)&&(a2>=a3))k=2,sum[2]++;
        else k=3,sum[3]++;
    }
    int rt(){
        if(k==1)return a1;
        else if(k==2)return a2;
        else return a3;
    }
}s[K];
bool cmp(stu x,stu y){
    return x.k<y.k;
}
bool cmd1(stu x,stu y){
    return min(x.a1-x.a2,x.a1-x.a3)>min(y.a1-y.a2,y.a1-y.a3);
}
bool cmd2(stu x,stu y){
    return min(x.a2-x.a1,x.a2-x.a3)>min(y.a2-y.a1,y.a2-y.a3);
}
bool cmd3(stu x,stu y){
    return min(x.a3-x.a1,x.a3-x.a2)>min(y.a3-y.a1,y.a3-y.a2);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        ans=0;
        cin>>n;
        memset(sum,0,sizeof(sum));
        for(int j=0;j<n;j++)s[j].in();
        sort(s,s+n,cmp);
        int s1=0,s2=0,s3=0;
        for(int j=0;j<n;j++){
            if(s[j].k!=1)break;
            else s1++;
        }for(int j=s1;j<n;j++){
            if(s[j].k!=2)break;
            else s2++;
        }for(int j=s1+s2;j<n;j++){
            s3++;
        }
        for(int i=0;i<=10;i++){
            if(s1>n/2){
                sort(s,s+s1,cmd1);
                for(int j=n/2;j<s1;j++){
                    if(s[j].a2<s[j].a3)s3++,s1--,s[j].k=3;
                    else s2++,s1--,s[j].k=2;
                }sort(s,s+n,cmp);
            }if(s2>n/2){
                sort(s+s1,s+s1+s2,cmd2);
                for(int j=s1+n/2;j<s1+s2;j++){
                    if(s[j].a1<s[j].a3)s3++,s2--,s[j].k=3;
                    else s1++,s2--,s[j].k=1;
                }sort(s,s+n,cmp);
            }if(s3>n/2){
                sort(s+s1+s2,s+s1+s2+s3,cmd2);
                for(int j=s1+s2+n/2;j<s1+s2+s3;j++){
                    if(s[j].a1<s[j].a2)s2++,s3--,s[j].k=2;
                    else s1++,s3--,s[j].k=1;
                }sort(s,s+n,cmp);
            }
        }
        for(int j=0;j<n;j++)ans+=s[j].rt();
        cout<<ans<<endl;
    }fclose(stdin);
    fclose(stdout);
    return 0;
}