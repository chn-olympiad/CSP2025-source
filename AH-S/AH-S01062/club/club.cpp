#include<iostream>
#include<algorithm>
using namespace std;
int t,n,a[100005],b[100005],c[100005],d[100005],e[5],sum,g;
struct node{
    int num,id;
}f[100005];
bool cmp(node x,node y){
    return x.num>y.num;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        sum=0;
        g=0;
        e[1]=e[2]=e[3]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]>=b[i]&&a[i]>=c[i]){
                d[i]=1;
                e[d[i]]++;
            }else if(a[i]<=b[i]&&b[i]>=c[i]){
                d[i]=2;
                e[d[i]]++;
            }else{
                d[i]=3;
                e[d[i]]++;
            }
        }
        if(e[1]>n/2||e[2]>n/2||e[3]>n/2){
            if(e[1]>n/2){
                for(int i=1;i<=n;i++){
                    if(d[i]==1){
                        f[++g]=(node){a[i]-max(b[i],c[i]),i};
                    }else{
                        sum+=max(b[i],c[i]);
                    }
                }
                sort(f+1,f+e[1]+1,cmp);
                for(int i=1;i<=n/2;i++){
                    sum+=f[i].num+max(c[f[i].id],b[f[i].id]);
                }
                for(int i=n/2+1;i<=e[1];i++){
                    int p=f[i].id;
                    if(b[p]>c[p]){
                        sum+=b[p];
                    }else{
                        sum+=c[p];
                    }
                }
            }else if(e[2]>n/2){
                for(int i=1;i<=n;i++){
                    if(d[i]==2){
                        f[++g]=(node){b[i]-max(a[i],c[i]),i};
                    }else{
                        sum+=max(a[i],c[i]);
                    }
                }
                sort(f+1,f+e[2]+1,cmp);
                for(int i=1;i<=n/2;i++){
                    sum+=f[i].num+max(a[f[i].id],c[f[i].id]);
                }
                for(int i=n/2+1;i<=e[2];i++){
                    int p=f[i].id;
                    if(a[p]>c[p]){
                        sum+=a[p];
                    }else{
                        sum+=c[p];
                    }
                }
            }else{
                for(int i=1;i<=n;i++){
                    if(d[i]==3){
                        f[++g]=(node){c[i]-max(b[i],a[i]),i};
                    }else{
                        sum+=max(a[i],b[i]);
                    }
                }
                sort(f+1,f+e[3]+1,cmp);
                for(int i=1;i<=n/2;i++){
                    sum+=f[i].num+max(a[f[i].id],b[f[i].id]);
                }
                for(int i=n/2+1;i<=e[3];i++){
                    int p=f[i].id;
                    if(b[p]>a[p]){
                        sum+=b[p];
                    }else{
                        sum+=a[p];
                    }
                }
            }
        }else{
            for(int i=1;i<=n;i++){
                sum+=max(a[i],max(b[i],c[i]));
            }
        }
        cout<<sum<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
