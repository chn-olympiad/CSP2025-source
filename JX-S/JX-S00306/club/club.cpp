#include<bits/stdc++.h>
using namespace std;
struct club{
    int A;
    int B;
    int C;
    int mid;
    int ma;
};
bool cmp(club d,club e){
    return d.ma-d.mid<e.ma-e.mid;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int ans=0;
        club a[100001]={},b[100001]={};
        int c[100001]={};
        club s;
        s.A=0;
        s.B=0;
        s.C=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].A>>a[i].B>>a[i].C;
            if((a[i].A>=a[i].B and a[i].B>=a[i].C) or (a[i].B>=a[i].A and a[i].A>=a[i].C)){
                a[i].C=0;
                a[i].ma=max(a[i].A,a[i].B);
                ans+=max(a[i].A,a[i].B);
                a[i].mid=min(a[i].A,a[i].B);
                if(a[i].ma==a[i].A){
                    s.A++;
                }
                else{
                    s.B++;
                }
            }
            else if((a[i].A>=a[i].C and a[i].C>=a[i].B) or (a[i].C>=a[i].A and a[i].A>=a[i].B)){
                a[i].B=0;
                a[i].ma=max(a[i].A,a[i].C);
                ans+=max(a[i].A,a[i].C);
                a[i].mid=min(a[i].A,a[i].C);
                if(a[i].ma==a[i].A){
                    s.A++;
                }
                else{
                    s.C++;
                }
            }
            else{
                a[i].A=0;
                a[i].mid=min(a[i].C,a[i].B);
                ans+=max(a[i].C,a[i].B);
                a[i].ma=max(a[i].A,a[i].C);
                if(a[i].ma==a[i].C){
                    s.C++;
                }
                else{
                    s.B++;
                }
            }
        }
        sort(a+1,a+1+n,cmp);
        if(s.A>n/2){
            for(int i=1;i<=n;i++){
                if(a[i].ma==a[i].A){
                    ans=ans+a[i].mid-a[i].A;
                    s.A--;
                }
                if(s.A<=n/2){
                    break;
                }
            }
        }
        else if(s.B>n/2){
            for(int i=1;i<=n;i++){
                if(a[i].ma==a[i].B){
                    ans=ans+a[i].mid-a[i].B;
                    s.B--;
                }
                if(s.B<=n/2){
                    break;
                }
            }
        }
        else if(s.C>n/2){
            for(int i=1;i<=n;i++){
                if(a[i].ma==a[i].C){
                    ans=ans+a[i].mid-a[i].C;
                    s.C--;
                }
                if(s.C<=n/2){
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
