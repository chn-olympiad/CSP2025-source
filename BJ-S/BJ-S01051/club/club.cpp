#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t;
struct node{
    int s1,s2,s3;
}a[N],seq1[N],seq2[N],seq3[N];
bool cmp1(node a,node b){
    return a.s3-a.s1>b.s3-b.s1;
}
bool cmp2(node a,node b){
    return a.s3-a.s2>b.s3-b.s2;
}
bool cmp3(node a,node b){
    return a.s2-a.s1>b.s2-b.s1;
}
bool cmp4(node a,node b){
    return a.s2-a.s3>b.s2-b.s3;
}
bool cmp5(node a,node b){
    return a.s1-a.s2>b.s1-b.s2;
}
bool cmp6(node a,node b){
    return a.s1-a.s3>b.s1-b.s3;
}
bool cmp7(node a,node b){
    //if(a.s2-a.s3==b.s2-b.s3)
        //return a.s1<b.s1;
    //else
        //return a.s2-a.s3>b.s2-b.s3;
    if(a.s2==b.s2)
        return a.s3>b.s3;
    else
        return a.s2>b.s2;
    //if(a.s2==b.s2)
        //return a.s3>b.s3;
    //else if(a.s3==b.s3)
        //return a.s2>b.s2;
    //else
        //return a.s2-a.s1<b.s2-b.s1;
}
bool cmp8(node a,node b){
    //if(a.s1-a.s3==b.s1-b.s3)
        //return a.s1-a.s3>b.s1-b.s3;
    //else
        //return a.s2<b.s2;
    if(a.s1==b.s1)
        return a.s3>b.s3;
    else
        return a.s1>b.s1;
    //if(a.s1==b.s1)
        // a.s3>b.s3;
    //else if(a.s3==b.s3)
        //return a.s1>b.s1;
    //else
        //return a.s1-a.s2<b.s1-b.s2;
}
bool cmp9(node a,node b){
    //if(a.s1-a.s2>b.s1-b.s2)
        //return a.s3<b.s3;
    //else
        //return a.s1-a.s2>b.s1-b.s2;
    if(a.s1==b.s1)
        return a.s2>b.s2;
    else
        return a.s1>b.s1;
    //if(a.s1==b.s1)
        //return a.s2>b.s2;
    //else if(a.s2==b.s2)
        //return a.s1>b.s1;
    //else
        //return a.s1-a.s3<b.s1-b.s3;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        int n,cnt1=0,cnt2=0,cnt3=0,sum1=0,sum2=0,sum3=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i].s1,&a[i].s2,&a[i].s3);
            int mx=max({a[i].s1,a[i].s2,a[i].s3});
            if(mx==a[i].s1){
                cnt1++;
                sum1+=a[i].s1;
                seq1[cnt1]=a[i];
            }else if(mx==a[i].s2){
                cnt2++;
                sum2+=a[i].s2;
                seq2[cnt2]=a[i];
            }else{
                cnt3++;
                sum3+=a[i].s3;
                seq3[cnt3]=a[i];
            }
        }
        if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2)
            printf("%lld\n",sum1+sum2+sum3);
        else{
            if(cnt1>n/2&&cnt2>n/2){
                sort(seq1+1,seq1+cnt1+1,cmp1);
                for(int i=1;i<=cnt1-n/2;i++){
                    sum1-=a[i].s1;
                    sum3+=a[i].s3;
                }
                sort(seq2+1,seq2+cnt2+1,cmp2);
                for(int i=1;i<=cnt2-n/2;i++){
                    sum2-=a[i].s2;
                    sum3+=a[i].s3;
                }
            }else if(cnt1>n/2&&cnt3>n/2){
                sort(seq1+1,seq1+cnt1+1,cmp3);
                for(int i=1;i<=cnt1-n/2;i++){
                    sum1-=a[i].s1;
                    sum2+=a[i].s2;
                }
                sort(seq3+1,seq3+cnt3+1,cmp4);
                for(int i=1;i<=cnt3-n/2;i++){
                    sum3-=a[i].s3;
                    sum2+=a[i].s2;
                }
            }else if(cnt2>n/2&&cnt3>n/2){
                sort(seq2+1,seq2+cnt2+1,cmp5);
                for(int i=1;i<=cnt2-n/2;i++){
                    sum2-=a[i].s2;
                    sum1+=a[i].s1;
                }
                sort(seq3+1,seq3+cnt3+1,cmp6);
                for(int i=1;i<=cnt3-n/2;i++){
                    sum3-=a[i].s3;
                    sum1+=a[i].s1;
                }
            }else if(cnt1>n/2){
                sort(seq1+1,seq1+cnt1+1,cmp7);
                for(int i=1;i<=cnt1;i++){
                    //cout<<seq1[i].s1<<" "<<seq1[i].s2<<" "<<seq1[i].s3<<endl;
                    int s1=seq1[i].s1,s2=seq1[i].s2,s3=seq1[i].s3;
                    if(s2-s1>=s3-s1||cnt3==n/2){
                        sum1-=s1;
                        cnt1--;
                        sum2+=s2;
                        cnt2++;
                    }else if(s3-s1>s2-s1||cnt2==n/2){
                        sum1-=s1;
                        cnt1--;
                        sum3+=s3;
                        cnt3++;
                    }
                }
            }else if(cnt2>n/2){
                sort(seq2+1,seq2+cnt2+1,cmp8);
                for(int i=1;i<=cnt2;i++){
                    //cout<<seq2[i].s1<<" "<<seq2[i].s2<<" "<<seq2[i].s3<<endl;
                    int s1=seq2[i].s1,s2=seq2[i].s2,s3=seq2[i].s3;
                    if(s1-s2>=s3-s2||cnt3==n/2){
                        sum2-=s2;
                        cnt2--;
                        sum1+=s1;
                        cnt1++;
                    }else if(s3-s2>s1-s2||cnt1==n/2){
                        sum2-=s2;
                        cnt2--;
                        sum3+=s3;
                        cnt3++;
                    }
                }
            }else if(cnt3>n/2){
                sort(seq3+1,seq3+cnt3+1,cmp9);
                for(int i=1;i<=cnt3;i++){
                    //cout<<seq3[i].s1<<" "<<seq3[i].s2<<" "<<seq3[i].s3<<endl;
                    int s1=seq3[i].s1,s2=seq3[i].s2,s3=seq3[i].s3;
                    if(s1-s3>=s2-s3||cnt2==n/2){
                        sum3-=s3;
                        cnt3--;
                        sum1+=s1;
                        cnt1++;
                    }else if(s2-s3>s1-s3||cnt1==n/2){
                        sum3-=s3;
                        cnt3--;
                        sum2+=s2;
                        cnt2++;
                    }
                }
            }
            printf("%lld\n",sum1+sum2+sum3);
        }
    }
    return 0;
}
