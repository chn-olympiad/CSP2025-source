 #include<bits/stdc++.h>
 using namespace std;
 int a[500001],n,k,ans=0,x;
 int xro(int a,int b){
     int a1[64],b1[64],l1=0,l2=0,c=0;
     while(a){
         a1[++l1]=a%2;
         a/=2;
     }while(b){
         b1[++l2]=b%2;
         b/=2;
     }for(int i=1;i<=max(l1,l2);i++){
         if(a1[i]!=b1[i])c+=pow(2,i-1);
    }return c;
 }
 int orr(int l,int r){
     int c=a[l];
     for(int i=l+1;i<=r;i++){
         c=xro(c,a[i]);
     }return c;
 }
 int main(){
     freopen("xor.in","r",stdin);
     freopen("xor.out","w",stdout);
     cin>>n>>k;
     for(int i=1;i<=n;i++){
         cin>>a[i];
    }x=1;
     for(int i=1;i<=n;i++){
         for(int j=x;j<=i;j++){
             if(orr(j,i)==k){
                 x=i+1;
                 ans++;
                 break;
             }
         }
     }cout<<ans;
     fclose(stdin);
     fclose(stdout);
 }
