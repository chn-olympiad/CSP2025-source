#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,res=0;
struct ren{
    ll a1,a2,a3,a12,a13,a23;
};
ren a[100005];
ll a1r[100005],a2r[100005],a3r[100005];
ll a1s=0,a2s=0,a3s=0;
ll aa1=0,aa3=0,aa2=0;
bool flag=false;
bool cmpa1s(ll a6,ll b6){
    return a[a6].a1-max(a[a6].a2,a[a6].a3)<a[b6].a1-max(a[b6].a2,a[b6].a3);
}
bool cmpa2s(ll a6,ll b6){
    return a[a6].a2-max(a[a6].a1,a[a6].a3)<a[b6].a2-max(a[b6].a1,a[b6].a3);
}
bool cmpa3s(int a6,int b6){
    return a[a6].a3-max(a[a6].a2,a[a6].a1)<a[b6].a3-max(a[b6].a2,a[b6].a1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(ll i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            a[i].a12=abs(a[i].a1-a[i].a2);
            a[i].a23=abs(a[i].a3-a[i].a2);
            a[i].a13=abs(a[i].a1-a[i].a3);
            if(a[i].a1>a[i].a2 && a[i].a1>a[i].a3){
                res+=a[i].a1;
                a1s++;
                a1r[a1s]=i;
            }
            if(a[i].a2>a[i].a1 && a[i].a2>a[i].a3){
                res+=a[i].a2;
                a2s++;
                a2r[a2s]=i;
            }
            if(a[i].a3>a[i].a2 && a[i].a3>a[i].a1){
                res+=a[i].a3;
                a3s++;
                a3r[a3s]=i;
            }
        }
        if(a1s>n/2){
            for(int i=1;i<=a1s;i++){
                if(a[a1r[i]].a12<a[a1r[i]].a13){
                    aa2+=a[a1r[i]].a2;
                }
                else/* if(a[a1r[a1z]].a12>a[a1r[a1z]].a13)*/{
                    aa3+=a[a1r[i]].a3;
                }
            }
            int a1z=1;
            sort(a1r+1,a1r+a1s+1,cmpa1s);
            while(a1s>n/2){
                if(a2s==n/2 || a3s==n/2){
                    flag=true;
                    break;
                }
                if(a[a1r[a1z]].a12>a[a1r[a1z]].a13){
                    res-=a[a1r[a1z]].a13;
                    a1s--;a3s++;
                    aa3-=a[a1r[a1z]].a3;

                }
                else if(a[a1r[a1z]].a12<a[a1r[a1z]].a13){
                    res-=a[a1r[a1z]].a12;
                    a1s--;a2s++;
                    aa2-=a[a1r[a1z]].a2;
                }
                else{
                    if(a2s<a3s){
                        res-=a[a1r[a1z]].a12;
                        a1s--;a2s++;
                        aa2-=a[a1r[a1z]].a2;
                    }
                    else if(a2s>a3s){
                        res-=a[a1r[a1z]].a13;
                        a1s--;a3s++;
                        aa3-=a[a1r[a1z]].a3;
                    }
                    else{
                        if(aa2>aa3){
                            res-=a[a1r[a1z]].a12;
                            a1s--;a2s++;
                            aa2-=a[a1r[a1z]].a2;
                        }
                        else{
                            res-=a[a1r[a1z]].a13;
                            a1s--;a3s++;
                            aa3-=a[a1r[a1z]].a3;
                        }
                    }
                }
                a1z++;
            }
            if(flag){
                if(a2s==n/2) res-=a[a1r[a1z]].a13;
                else res-=a[a1r[a1z]].a12;
            }
        }
        else if(a2s>n/2){
            for(int i=1;i<=a2s;i++){
                if(a[a2r[i]].a12<a[a2r[i]].a23){
                    aa1+=a[a1r[i]].a1;
                }
                else/* if(a[a1r[a1z]].a12>a[a1r[a1z]].a13)*/{
                    aa3+=a[a1r[i]].a3;
                }
            }
            int a2z=1;
            sort(a2r+1,a2r+a2s+1,cmpa2s);
            while(a2s>n/2){
                if(a1s==n/2 || a3s==n/2){
                    flag=true;
                    break;
                }
                if(a[a2r[a2z]].a12>a[a2r[a2z]].a23){
                    res-=a[a2r[a2z]].a23;
                    a2s--;a3s++;
                    aa3-=a[a2r[a2z]].a3;
                }
                else if(a[a2r[a2z]].a12<a[a2r[a2z]].a23){
                    res-=a[a2r[a2z]].a12;
                    a2s--;a1s++;
                    aa1-=a[a2r[a2z]].a1;
                }
                else{
                    if(a1s<a3s){
                        res-=a[a2r[a2z]].a12;
                        a2s--;a1s++;
                        aa1-=a[a2r[a2z]].a1;
                    }
                    else if(a1s>a3s){
                        res-=a[a2r[a2z]].a23;
                        a2s--;a3s++;
                        aa3-=a[a2r[a2z]].a3;
                    }
                    else{
                        if(aa1>aa3){
                            res-=a[a2r[a2z]].a23;
                            a2s--;a3s++;
                            aa3-=a[a2r[a2z]].a3;
                        }
                        else{
                            res-=a[a2r[a2z]].a12;
                            a2s--;a1s++;
                            aa1-=a[a2r[a2z]].a1;
                        }
                    }
                }
                a2z++;
            }
            if(flag){
                if(a1s==n/2) res-=a[a2r[a2z]].a23;
                else res-=a[a2r[a2z]].a12;
            }

        }
        else{
            for(int i=1;i<=a3s;i++){
                if(a[a3r[i]].a23<a[a3r[i]].a13){
                    aa2+=a[a1r[i]].a2;
                }
                else/* if(a[a1r[a1z]].a12>a[a1r[a1z]].a13)*/{
                    aa3+=a[a1r[i]].a3;
                }
            }
            int a3z=1;
            sort(a3r+1,a3r+a3s+1,cmpa3s);
            while(a3s>n/2){
                if(a2s==n/2 || a1s==n/2){
                    flag=true;
                    break;
                }
                if(a[a3r[a3z]].a23>a[a3r[a3z]].a13){
                    res-=a[a3r[a3z]].a13;
                    a3s--;a1s++;
                    aa1-=a[a3r[a3z]].a1;
                }
                else if(a[a3r[a3z]].a23<a[a3r[a3z]].a13){
                    res-=a[a3r[a3z]].a23;
                    a3s--;a2s++;
                    aa2-=a[a3r[a3z]].a2;
                }
                else{
                    if(a2s<a1s){
                        res-=a[a3r[a3z]].a23;
                        a3s--;a2s++;
                        aa2-=a[a3r[a3z]].a1;
                    }
                    else if(a2s>a1s){
                        res-=a[a3r[a3s]].a13;
                        a3s--;a1s++;
                        aa1-=a[a3r[a3z]].a1;
                    }
                    else{
                        if(aa1>aa2){
                            res-=a[a3r[a3z]].a23;
                            a3s--;a2s++;
                            aa2-=a[a3r[a3z]].a1;
                        }
                        else{
                            res-=a[a3r[a3s]].a13;
                            a3s--;a1s++;
                            aa1-=a[a3r[a3z]].a1;
                        }
                    }
                }
                a3z++;
            }
            if(flag){
                if(a1s==n/2) res-=a[a3r[a3z]].a23;
                else res-=a[a3r[a3z]].a13;
            }

        }
        cout<<res<<endl;
        aa1=aa2=aa3=a1s=a2s=a3s=n=res=0;
        memset(a1r,0,100005);
        memset(a2r,0,100005);
        memset(a3r,0,100005);
    }
    //fclose("club.in");fclose("club.out");
    return 0;
}
