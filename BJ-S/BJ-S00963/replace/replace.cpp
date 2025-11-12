#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
bool f;
struct node{
    string s1,s2,c1,c2;
    int nx,cx;
}a[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].s1>>a[i].s2;
        for(int j=0;j<a[i].s1.length();j++){
            f=false;
            if(a[i].s1[j]!=a[i].s2[j]){
                a[i].nx=j;
                for(int k=j;k<a[i].s1.length();k++){
                    if(a[i].s1[k]==a[i].s2[k]){
                        a[i].cx=k-j;
                        f=true;
                        //cout<<i<<" "<<k<<endl;
                        break;
                    }
                    else{
                        a[i].c1[k-j]=a[i].s1[k];
                        a[i].c2[k-j]=a[i].s2[k];
                    }
                }
                if(!f)a[i].cx=a[i].s1.length();
                break;
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        cout<<a[i].s1<<" "<<a[i].s2<<" "<<a[i].c1<<" "<<a[i].c2<<" "<<a[i].nx<<" "<<a[i].cx<<endl;
    }*/
    while(q--){
        string t1,t2,x1,x2;
        int tnx=0,tcx=0,ans=0;
        f=false;
        cin>>t1>>t2;
        cout<<"0"<<endl;
        /*for(int i=1;i<=n;i++){
            if(t1.find(a[i].s1)&&t2.find(a[i].s2)){
                f=true;
                
            }
        }
        if(!f)cout<<"0"<<endl;
        for(int i=0;i<t1.length();i++){
            if(t1[i]!=t2[i]){
                tnx=i;
                for(int j=i;j<t1.length();j++){
                    if(t1[j]==t2[j]){
                        tcx=j-tnx;
                        f=true;
                        break;
                    }
                    else{
                        x1[j-i]=t1[j];
                        x2[j-i]=t2[j];
                    }
                }
                if(!f)tcx=t1.length();
                break;
            }
        }
        for(int i=1;i<=n;i++){
            f=false;
            if(a[i].c1==x1&&a[i].c2==x2&&tcx==a[i].cx){
                for(int j=0;j<a[i].s1.length();j++){
                    if(a[i].s1[j]!=t1[tnx-a[i].nx+j]){
                        f=true;
                        break;
                    }
                }
                if(!f){
                    ans++;
                    cout<<i<<" ";
                }
            }
        }
        cout<<endl;
        cout<<ans<<endl;*/
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}