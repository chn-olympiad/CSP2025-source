#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in",r,in);
    freopen("club.out",w,out);
    int t,n,sum;
    cin>>t;
    int a[20000],b[20000],c[20000];
    for(int j=0;j<t;j++){
        sum=0;
        cin>>n;
        int club1=0,club2=0,club3=0;
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int i=0;i<n;i++){
            if(a[i]>b[i]&&a[i]>c[i]){
                if(club1<=n/2-1){
                    sum+=a[i];
                    club1++;
                }else{
                    if(b[i]>c[i]){
                        if(club2+1<=n/2){
                            club2++;
                            sum+=b[i];
                            continue;
                        }
                    }else{
                        sum+=c[i];
                        club3++;
                        continue;
                    }
                }
            }else if(b[i]>a[i]&&b[i]>c[i]){
                if(club2<=n/2-1){
                    sum+=b[i];
                    club2++;
                }else{
                    if(a[i]>c[i]){
                        if(club1+1<=n/2){
                            club1++;
                            sum+=a[i];
                            continue;
                        }
                    }else{

                        sum+=c[i];
                        club3+=1;
                        continue;
                    }
                }
            }else if(c[i]>b[i]&&a[i]<c[i]){
                if(club3<=n/2-1){
                    sum+=c[i];
                    club3++;
                }else{
                    if(a[i]>b[i]){
                        if(club1+1<=n/2){
                            club1++;
                            sum+=a[i];
                        }
                    }else{
                        club2++;
                        sum+=b[i];
                    }
                }
            }

        }
        cout<<sum<<endl;
    }
    return 0;
}
