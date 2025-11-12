#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,a[5010],ans=0,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        for(int j=2;j<i;j++){
            for(int k=1;k<j;k++){
                    for(int b=0;b<k;b++){
                        if(b<=0){
                            continue;
                        }
                        for(int c=-1;c<b;c++){
                                if(c<=0){
                            continue;
                        }
                            for(int d=-2;d<c;d++){
                                if(d<=0){
                            continue;
                        }
                                for(int e=-3;e<d;e++){
                                    if(e<=0){
                            continue;
                        }
                                    for(int f=-4;f<e;f++){
                                        if(f<=0){
                            continue;
                        }
                        for(int g=-5;g<f;g++){
                                        if(g<=0){
                            continue;
                        }
                        for(int h=-6;h<g;h++){
                                        if(h<=0){
                            continue;
                        }
                        for(int l=-7;l<h;l++){
                                        if(l<=0){
                            continue;
                        }
                        for(int m=-8;m<l;m++){
                                        if(m<=0){
                            continue;
                        }
                        for(int o=-9;o<m;o++){
                                        if(o<=0){
                            continue;
                        }
                        for(int p=-10;p<o;p++){
                                        if(p<=0){
                            continue;
                        }
                        for(int q=-11;q<p;q++){
                                        if(q<=0){
                            continue;
                        }
                        for(int r=-12;r<q;r++){
                                        if(r<=0){
                            continue;
                        }
                        for(int s=-13;s<r;s++){
                                        if(s<=0){
                            continue;
                        }
                        for(int u=-14;u<s;u++){
                                        if(u<=0){
                            continue;
                        }
                        for(int v=-15;v<u;v++){
                                        if(v<=0){
                            continue;
                        }
                        for(int w=-16;w<v;w++){
                                        if(w<=0){
                            continue;
                        }
                if(a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[u]+a[v]+a[w]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[u]+a[v]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[u]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]+a[q]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]+a[d]+a[e]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]+a[d]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]+a[c]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]+a[b]>a[i]){
                    ans++;
                }
            }
                if(a[j]+a[k]>a[i]){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
