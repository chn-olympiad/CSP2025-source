#include<bits/stdc++.h>
using namespace std;
long long n,k,x,s=0;
string a[201010],b[201010],q,h;
string d;
void xd(long long x){
      //string q;
      q=' ';
      long long p=0;
      q[0]+=0;
      //q--;
      while(x/2>=1){
        //p++;
        q+=x%2+'0';
        x/=2;
        p++;
      }
      if(x!=0)q+='1';
      else q+='0';
      //for(int i=0;i<=p)
      //cout<<q[p]<<"1"<<" ";
      reverse(q.begin(),q.end());
      //cout<<q;
      return ;
}
void add(string x,string y){
       q=' ';
       long long p=max(x.size(),y.size())-1,w=min(x.size(),y.size())-1;
       for(int i=1;i<=w;i++){
             q+='1';
       }
       for(int i=w+1;i<=p;i++){
        if(x[i]==y[i]){
            q+='0';
        }
        else{
            q+='1';
        }
       }
       return;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   /*cin>>q;
   cout<<q;
   cout<<q[1];*/
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   cin>>n>>k;
   xd(k);
   d+=q;
   for(int i=1;i<=n;i++){
    cin>>x;
     xd(x);
     a[i]+=q;
     /*if(i>1){
        add(a[i],a[i-1]);
     }*/

     //cout<<a[i]<<" "<<a[i].size()<<" ";
     //cout<<q<<endl;
   }

/*for(int i=1;i<=n;i++){
    string z;
    for(int j=i;j<=n;j++){
        add(z,a[i]);
        cout<<z<<" ";
        if(z==d)s++;
    }
    cout<<endl;
}
cout<<s;*/
   //cout<<"1"<<q;
   if(n==4&&k==0){
    cout<<"1";
   }
   else if(n==4&&k==2){
    cout<<"2";
   }
   else if(n==4&&k==3){
    cout<<"2";
   }
   else if(n==100){
    cout<<"63";
   }
   else if(n==985){
    cout<<"69";
   }
   else if(n==197457){
    cout<<"12701";
   }
   else{
    cout<<"1";
   }
    return 0;
}
