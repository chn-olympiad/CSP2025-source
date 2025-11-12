#include<bits/stdc++.h>
using namespace std;
int n,q,num,suml,sumr,ans;
struct point{
    int l,sa,sb;
    string a,b,x,y,_y,z;
}a[200010];
string x,y;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b;
        a[i].l=a[i].a.size();
        a[i].a=" "+a[i].a;
        a[i].b=" "+a[i].b;
        num+=a[i].l;

    }
    //if(n<=100&&q<=100&&num<=200){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i].l;j++){
                if(a[i].a[j]=='b')a[i].sa=j;
                if(a[i].b[j]=='b')a[i].sb=j;
            }
            suml=1,sumr=a[i].l;
            while(a[i].a[suml]==a[i].b[suml]){
                a[i].x+=a[i].a[suml];
                suml++;
            }
            while(a[i].a[sumr]==a[i].b[sumr]){
                a[i].z=a[i].a[sumr]+a[i].z;
                sumr--;
            }
            for(int j=suml;j<=sumr;j++)a[i].y+=a[i].a[j],a[i]._y+=a[i].b[j];
        }
        while(q--){
            ans=0;
            cin>>x>>y;
            if(x.size()!=y.size()){
                cout<<0<<endl;
                continue;
            }
            int ln=x.size();
            string nx,ny,_ny,nz;
            suml=0,sumr=ln-1;
            while(x[suml]==y[suml]){
                nx+=x[suml];
                suml++;
            }
            while(x[sumr]==y[sumr]){
                nz=x[sumr]+nz;
                sumr--;
            }
            for(int j=suml;j<=sumr;j++)ny+=x[j],_ny+=y[j];
            //cout<<nx<<" "<<nz<<" "<<ny<<" "<<_ny<<endl;
            for(int i=1;i<=n;i++){
                bool flag=1;
                if(a[i].x.size()>nx.size()||a[i].z.size()>nz.size())continue;
                if(ny!=a[i].y||_ny!=a[i]._y)continue;
                for(int j=0;j<a[i].x.size();j++){
                    if(nx[nx.size()-a[i].x.size()+j]!=a[i].x[j]){
                        flag=0;
                        break;
                    }
                }
                if(flag==0)continue;
                for(int j=0;j<a[i].z.size();j++){
                    if(nz[j]!=a[i].z[j]){
                        flag=0;
                        continue;
                    }
                }
                if(flag==0)continue;
                ans++;
            }
            cout<<ans<<endl;
        }
   // }
    return 0;
}
