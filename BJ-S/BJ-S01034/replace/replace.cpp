#include<bits/stdc++.h>
using namespace std;
int n,q,ll,l[3333],ans;
char c1[1000010],c2[1000010],c[2010][2050];
bool check(){

}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>c1>>c2;
        l[i*2-1]=strlen(c1);
        l[i*2]=strlen(c2);
        ll=max(ll,l[i*2-1]);
        for(int j=0;j<l[i*2-1];j++){
            c[i*2-1][j]=c1[j];
            c[i*2][j]=c2[j];
            //cout<<c[i*2][j]<<" "<<c2[j]<<endl;
        }
    }

    while(q--){
        ans=0;
        cin>>c1>>c2;
        int l1=strlen(c1);
        int l2=strlen(c2);
        if(l1!=l2){
            cout<<0<<endl;
            continue;
        }
        int cnt=0;
        for(int i=0;i<l1;i++){
            if(c1[i]!=c2[i]) cnt++;
        }
        if(cnt>ll){
            cout<<0<<endl;
            continue;
        }
        c1[l1]=114;
        c2[l1]=114;
        for(int i=1;i<=n;i++){
            int cnt=0,k=0,bzd=0,pp=0;
            int a=i*2-1;
            for(int j=0;j<=l1;j++){
               // cout<<i<<" "<<j<<" "<<k<<endl;
              //  if(pp==0&&c1[j]!=c[a][k]) continue;
              //  cout<<c[1][0]<<" "<<c1[j]<<endl;
                if(c[a][k]==c1[j]){
                 //   cout<<i<<" "<<j<<" "<<k<<endl;
                    cnt++;
                    k++;
                    continue;
                }
                else{
                    bzd=0;
                    //cout<<i<<" "<<j<<" "<<cnt<<" "<<l[a]<<" "<<endl;
                    if(cnt==l[a]-1){
                        for(int q=0;q<j-cnt-1;q++){
                            if(c1[q]!=c2[q]){
                                bzd=1;
                                break;
                            }
                        }
                        for(int q=j;q<l1-1;q++){
                            if(c1[q]!=c2[q]){
                                bzd=1;
                                break;
                            }
                        }
                        if(bzd==0){
                            ans++;
                        }
                        bzd=0;
                    }
                    cnt=0;
                    k=0;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
