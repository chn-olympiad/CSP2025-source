#include<bits/stdc++.h>
using namespace std;
long long n,a[5100],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        for(int j=i+1;a[i]<=a[j],j<=n;j++)
            for(int k=j+1;a[j]<=a[k],k<=n;k++){
                if(a[i]+a[j]>a[k])ans++;
                for(int l=k+1;a[k]<=a[l],l<=n;l++){
                    if(a[i]+a[j]+a[k]>a[l])ans++;
                    for(int m=l+1;a[l]<=a[m],m<=n;m++){
                        if(a[i]+a[j]+a[k]+a[l]>a[m])ans++;
                        for(int o=m+1;a[m]<=a[o],o<=n;o++){
                            if(a[i]+a[j]+a[k]+a[l]+a[m]>a[o])ans++;
                            for(int p=o+1;a[o]<=a[p],p<=n;p++){
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>a[p])ans++;
                                for(int q=p+1;a[p]<=a[q],q<=n;q++){
                                    if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>a[q])ans++;
                                    for(int r=q+1;a[q]<=a[r],r<=n;r++){
                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>a[r])ans++;
                                        for(int s=r+1;a[r]<=a[s],s<=n;s++){
                                            if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>a[s])ans++;
                                            for(int k1=s+1;a[s]<=a[k1],k1<=n;k1++){
                                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]>a[k1])ans++;
                                                for(int l1=k1+1;a[k1]<=a[l1],l1<=n;l1++){
                                                    if(a[i]+a[j]+a[k]+a[m]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[k1]>a[l1])ans++;
                                                    for(int m1=l1+1;a[l1]<=a[m1],m1<=n;m1++){
                                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[k1]+a[l1]>a[m1])ans++;
                                                        for(int o1=m1+1;a[m1]<=a[o1],o1<=n;o1++){
                                                            if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[k1]+a[s]+a[l1]+a[m1]>a[o1])ans++;
                                                            for(int p1=o1+1;a[o1]<=a[p1],p1<=n;p1++){
                                                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[k1]+a[s]+a[l1]+a[m1]+a[o1]>a[p1])ans++;
                                                                for(int q1=p1+1;a[p1]<=a[q1],q1<=n;q1++){
                                                                    if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[k1]+a[s]+a[l1]+a[m1]+a[o1]+a[p1]>a[q1])ans++;
                                                                    for(int r1=q1+1;a[q1]<=a[r1],r1<=n;r1++){
                                                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[k1]+a[s]+a[l1]+a[m1]+a[o1]+a[p1]+a[q1]>a[r1])ans++;
                                                                        for(int s1=r1+1;a[r1]<=a[s1],s1<=n;s1++){
                                                                            if(a[i]+a[j]+a[k]+a[l]+a[o]+a[m]+a[p]+a[q]+a[r]+a[k1]+a[s]+a[l1]+a[m1]+a[o1]+a[p1]+a[q1]+a[r1]>a[s1])ans++;
                                                                            for(int t1=s1+1;a[s1]<=a[t1],t1<=n;t1++){
                                                                                if(a[i]+a[j]+a[k]+a[l]+a[o]+a[m]+a[p]+a[q]+a[r]+a[k1]+a[s]+a[l1]+a[m1]+a[o1]+a[p1]+a[q1]+a[r1]+a[s1]>a[t1])ans++;
                                                                                for(int u1=t1+1;a[t1]<=a[u1],u1<=n;u1++){
                                                                                    if(a[i]+a[j]+a[k]+a[l]+a[o]+a[m]+a[p]+a[q]+a[r]+a[k1]+a[s]+a[l1]+a[m1]+a[o1]+a[p1]+a[q1]+a[r1]+a[s1]+a[t1]>a[u1])ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
    }}}}}}}}}
    cout<<ans%998244353;
    return 0;
}
