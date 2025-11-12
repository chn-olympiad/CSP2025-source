#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i1=1;i1<=n;i1++)
        for(int i2=i1+1;i2<=n;i2++)
            for(int i3=i2+1;i3<=n;i3++)
            if(max(a[i1],max(a[i2],a[i3]))*2<a[i1]+a[i2]+a[i3])ans++;
    if(n>=4)
    for(int i1=1;i1<=n;i1++)
        for(int i2=i1+1;i2<=n;i2++)
            for(int i3=i2+1;i3<=n;i3++)
                for(int i4=i3+1;i4<=n;i4++)
                        if(max(a[i1],max(a[i2],max(a[i3],a[i4])))*2<a[i1]+a[i2]+a[i3]+a[i4])ans++;
    if(n>=5)
    for(int i1=1;i1<=n;i1++)
        for(int i2=i1+1;i2<=n;i2++)
            for(int i3=i2+1;i3<=n;i3++)
                for(int i4=i3+1;i4<=n;i4++)
                    for(int i5=i4+1;i5<=n;i5++)
                        if(max(a[i1],max(a[i2],max(a[i3],max(a[i4],a[i5]))))*2<a[i1]+a[i2]+a[i3]+a[i4]+a[i5])ans++;
    if(n>=6)
    for(int i1=1;i1<=n;i1++)
        for(int i2=i1+1;i2<=n;i2++)
            for(int i3=i2+1;i3<=n;i3++)
                for(int i4=i3+1;i4<=n;i4++)
                    for(int i5=i4+1;i5<=n;i5++)
                        for(int i6=i5+1;i6<=n;i6++)
                            if(max(a[i1],max(a[i2],max(a[i3],max(a[i4],max(a[i5],a[i6])))))*2<a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6])ans++;
    if(n>=7)
    for(int i1=1;i1<=n;i1++)
        for(int i2=i1+1;i2<=n;i2++)
            for(int i3=i2+1;i3<=n;i3++)
                for(int i4=i3+1;i4<=n;i4++)
                    for(int i5=i4+1;i5<=n;i5++)
                        for(int i6=i5+1;i6<=n;i6++)
                            for(int i7=i6+1;i7<=n;i7++)
                                if(max(a[i1],max(a[i2],max(a[i3],max(a[i4],max(a[i5],max(a[i6],a[i7]))))))*2<a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7])ans++;
    if(n>=8)
    for(int i1=1;i1<=n;i1++)
        for(int i2=i1+1;i2<=n;i2++)
            for(int i3=i2+1;i3<=n;i3++)
                for(int i4=i3+1;i4<=n;i4++)
                    for(int i5=i4+1;i5<=n;i5++)
                        for(int i6=i5+1;i6<=n;i6++)
                            for(int i7=i6+1;i7<=n;i7++)
                                for(int i8=i7+1;i8<=n;i8++)
                                    if(max(a[i1],max(a[i2],max(a[i3],max(a[i4],max(a[i5],max(a[i6],max(a[i7],a[i8])))))))*2<a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8])ans++;
    if(n>=9)
    for(int i1=1;i1<=n;i1++)
        for(int i2=i1+1;i2<=n;i2++)
            for(int i3=i2+1;i3<=n;i3++)
                for(int i4=i3+1;i4<=n;i4++)
                    for(int i5=i4+1;i5<=n;i5++)
                        for(int i6=i5+1;i6<=n;i6++)
                            for(int i7=i6+1;i7<=n;i7++)
                                for(int i8=i7+1;i8<=n;i8++)
                                    for(int i9=i8+1;i9<=n;i9++)
                                        if(max(a[i1],max(a[i2],max(a[i3],max(a[i4],max(a[i5],max(a[i6],max(a[i7],max(a[i8],a[i9]))))))))*2<a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9])ans++;
    if(n>=10)
    for(int i1=1;i1<=n;i1++)
        for(int i2=i1+1;i2<=n;i2++)
            for(int i3=i2+1;i3<=n;i3++)
                for(int i4=i3+1;i4<=n;i4++)
                    for(int i5=i4+1;i5<=n;i5++)
                        for(int i6=i5+1;i6<=n;i6++)
                            for(int i7=i6+1;i7<=n;i7++)
                                for(int i8=i7+1;i8<=n;i8++)
                                    for(int i9=i8+1;i9<=n;i9++)
                                        for(int i10=i9+1;i10<=n;i10++)
                                            if(max(a[i1],max(a[i2],max(a[i3],max(a[i4],max(a[i5],max(a[i6],max(a[i7],max(a[i8],max(a[i9],a[i10])))))))))*2<a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10])ans++;
    cout<<ans;
    return 0;
}



