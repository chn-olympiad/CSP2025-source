
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,flag[4],sum;
struct aaa{
   int t1;
   int t2;
   int t3;
}a[N];
struct im{
   int v;
   int id;
   int se;
   int seid;
   int lst;
   int lstid;
}maxn[N],s[N];
bool cpp(im x,im y){
    return x.v>y.v;
}
int main(){
    int t;
    cin>>t;
   while(t--){
        cin>>n;
        memset(flag,0,sizeof(flag));
        memset(maxn,0,sizeof(0));
        memset(s,0,sizeof(0));
        sum=0;
        for(int i=1;i<=n;i++){
           cin>>a[i].t1>>a[i].t2>>a[i].t3;
           int bj[3];
           bj[1]=a[i].t1;
           bj[2]=a[i].t2;
           bj[3]=a[i].t3;
           sort(bj+1,bj+3+1);
           if(bj[3]==a[i].t1){
                maxn[i].v=bj[3];
                maxn[i].id=1;
               if(bj[2]==a[i].t2){
                   maxn[i].se=bj[2],maxn[i].seid=2;
                   maxn[i].lst=bj[1],maxn[i].lstid=3;
               }else if(bj[2]==a[i].t3){
                   maxn[i].se=bj[2],maxn[i].seid=3;
                   maxn[i].lst=bj[1],maxn[i].lstid=2;
               }
           }else if(bj[3]==a[i].t2){
                maxn[i].v=bj[3];
                maxn[i].id=2;
               if(bj[2]==a[i].t1){
                 maxn[i].se=bj[2],maxn[i].seid=1;
                   maxn[i].lst=bj[1],maxn[i].lstid=3;
               }else if(bj[2]==a[i].t3){
                  maxn[i].se=bj[2],maxn[i].seid=3;
                   maxn[i].lst=bj[1],maxn[i].lstid=1;
               }
           }else{
               maxn[i].v=bj[3];
                maxn[i].id=3;
               if(bj[2]==a[i].t1){
                    maxn[i].se=bj[2],maxn[i].seid=1;
                   maxn[i].lst=bj[1],maxn[i].lstid=2;

               }else if(bj[2]==a[i].t2){
                    maxn[i].se=bj[2],maxn[i].seid=2;
                   maxn[i].lst=bj[1],maxn[i].lstid=1;
               }
           }

        }sort(maxn+1,maxn+n+1,cpp);
       for(int i=1;i<=n;i++){
        cout<< maxn[i].v<<" "<< maxn[i].id<<" "<< maxn[i].se<<" "<< maxn[i].seid<<" "<< maxn[i].lst<<" "<< maxn[i].lstid<<endl;
        }

        int k=1;
        for(int i=1;i<=n;i++){
            if(flag[maxn[i].id]<n/2){
                flag[maxn[i].id]++;
                sum+=maxn[i].v;
            }else{

               for(int j=i;j<=n;j++,k++){
                   if(maxn[j].id==maxn[i].id){
                        s[k].id=maxn[j].seid;
                        s[k].lst=maxn[j].lst;
                        s[k].se=maxn[j].lst;
                        s[k].seid=maxn[j].lstid;
                        s[k].lstid=maxn[j].lstid;
                        s[k].v=maxn[j].se;
                   }else{
                        s[k].id=maxn[j].id;
                        s[k].lst=maxn[j].lst;
                        s[k].lstid=maxn[j].lstid;
                        s[k].v=maxn[j].v;
                        s[k].se=maxn[j].se;
                        s[k].seid=maxn[j].seid;
                   }
               }
              break;
            }

        }
        sort(s+1,s+k+1,cpp);
        for(int i=1;i<=k;i++){
            cout<< s[i].v<<" "<< s[i].id<<" "<< s[i].se<<" "<< s[i].seid<<" "<< s[i].lst<<" "<< s[i].lstid<<endl;
        }

        for(int i=1;i<=k;i++){
            if(flag[s[i].id]<n/2){
                flag[s[i].id]++;
                sum+=s[i].v;
            }else{
               for(int i=1;i<+n;i++){
                  if(flag[i]!=n/2){
                    sum+=s[i].v;
                  }
               }


            }

        }
        cout<<sum<<endl;
    }
   return 0;
}
