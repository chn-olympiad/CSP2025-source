#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],cnt,n,m,tmp,loca,local,locar;
bool cmp(int a,int b){
    return a>b;
}
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);

   cin>>n>>m;
   for(int i=1;i<=n*m;i++) cin>>a[i];
   tmp=a[1];
   //cout<<tmp<<endl;
   sort(a+1,a+n*m+1,cmp);
   //for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
   //cout<<endl;
   for(int i=1;i<=n*m;i++) if(a[i]==tmp) loca=i;
   //cout<<loca<<endl;
   local=loca/n;
   locar=loca%n;
   //cout<<local<<endl<<locar<<endl;
   if(locar>0) local++;
   if(locar==0){
        cout<<local<<" "<<n;
        return 0;
   }
   if(local%2==0)
   {
       cout<<local<<" "<<n-locar+1;
       return 0;
   }
   if(local%2==1)
   {
       cout<<local<<" "<<locar;
       return 0;
   }
   fclose(stdin);
   fclose(stdout);
}
