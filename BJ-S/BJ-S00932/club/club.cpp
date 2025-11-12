#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    for(int j=1;j<=t;j++){
            cin>>n;
            if(n==2){
        int g,h,k,l,m,o;
        cin>>g>>h>>k;
        cin>>l>>m>>o;
        if(g+m>=g+o && g+m>=h+l && g+m>=h+o && g+m>=k+l && g+m>=k+m){
            cout<<g+m;
        }
        else if(g+o>=g+m && g+o>=h+l && g+o>=h+o && g+o>=k+l && g+o>=k+m){
            cout<<g+o;
        }
        else if(h+l>=g+m && h+l>=g+o && h+l>=h+o && h+l>=k+l && h+l>=k+m){
            cout<<h+l;
        }
        else if(h+o>=g+m && h+o>=g+o && h+o>=h+l && h+o>=k+l && h+o>=k+m){
            cout<<h+o;
        }
        else if(k+l>=g+m && k+l>=g+o && k+l>=h+o && k+l>=h+l && k+l>=k+m){
            cout<<k+l;
        }
        else if(k+m>=g+m && k+m>=g+o && k+m>=h+o && k+m>=h+l && k+m>=k+l){
            cout<<k+m;
        }

    }
    else{
            int d=0;
            int e=0;
            int f=0;
            int sum=0;
            int a[100001]={0};
            int b[100001]={0};
            int c[100001]={0};
            for(int x=1;x<=n;x++){
                cin>>a[x]>>b[x]>>c[x];
            }
            for(int i=1;i<=n;i++){

                if(a[i]>=b[i] && a[i]>=c[i]){
                    d++;
                    if(d>n/2){
                        if(b[i]>=c[i]){
                           sum+=b[i];
                           e++;
                           }
                        else if(b[i]<c[i]){
                            sum+=c[i];
                            f++;
                        }
                        d--;
                    }
                    else{
                         sum+=a[i];
                    }

                }
                else if(b[i]>=a[i] && b[i]>=c[i]){
                        e++;
                        if(e>n/2){
                            if(a[i]>=c[i]){
                                sum+=a[i];
                                d++;
                            }
                            else if(a[i]<c[i]){
                                sum+=c[i];
                                f++;
                            }
                            e--;
                        }
                        else{
                             sum+=b[i];
                        }

                }
                else if(c[i]>=a[i] && c[i]>=b[i]){
                    f++;
                    if(f>n/2){
                        if(a[i]>=b[i]){
                            sum+=a[i];
                            d++;
                        }
                        else if(a[i]<b[i]){
                            sum+=b[i];
                            e++;
                        }
                        f--;
                    }
                    else{
                         sum+=c[i];
                    }

                }

    }

     cout<<sum<<endl;
    }

    }
    fclose(stdin);
    fclose(stdout);
return 0;
}