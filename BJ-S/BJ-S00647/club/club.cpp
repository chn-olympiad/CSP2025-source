#include<bits/stdc++.h>
using namespace std;

struct xs{
    int id;
    int myd;
};
bool cmp(xs a,xs b){
    if(a.myd==b.myd){
        if(a.id<b.id){
            return true;
        }
        else{
            return false;
        }
    }
    if(a.myd>b.myd){
        return true;
    }
    return false;
}
int club(int n,xs a[],xs b[],xs c[]){
    bool student[n]={false};
    int a1=0,b1=0,c1=0,ans=0;
    for(int i=0;i<n;i++){
        bool a2=false,b2=false,c2=false;

        if(a1>n/2||student[a[i].id]){
            a2=true;
           
            
        }
        if(b1>n/2||student[b[i].id]){
            b2=true;
            
        }
        if(c1>n/2||student[c[i].id]){
            c2=true;
            
        }

        if(a[i].id==b[i].id){
            if(a[i].myd>b[i].myd){
                b2=true;
            }
            else{
                a2=true;
            }
        }
        if(a[i].id==c[i].id){
            if(a[i].myd>c[i].myd){
                c2=true;
            }
            else{
                a2=true;
            }
        }
        if(b[i].id==c[i].id){
            if(b[i].myd>c[i].myd){
                c2=true;
            }
            else{
                b2=true;
            }
        }
        if(!a2){
            ans+=a[i].myd;
            student[a[i].id]=true;
            a1++;
            

        }
        if(!b2){
            ans+=b[i].myd;
            student[b[i].id]=true;
            b1++;
            

        if(!c2){
            ans+=c[i].myd;
            student[c[i].id]=true;
            c1++;
         

        }
    }

}
    return ans;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    cin>>n;
    xs a[100000];
    xs b[100000];
    xs c[100000];
    for(int i=0;i<n;i++){
        int n1;
        cin>>n1;
        for(int j=0;j<n1;j++){
            cin>>a[j].myd>>b[j].myd>>c[j].myd;
            a[j].id=j;
            b[j].id=j;
            c[j].id=j;
        }
        sort(a,a+n1,cmp);
        sort(b,b+n1,cmp);
        sort(c,c+n1,cmp);
        cout<<club(n1,a,b,c)<<endl;
      
    }
    return 0;
}