#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int t;
int n,num;
struct abc{
int a1,a2,a3;
bool lu;
}a[100000];
vector <int>  numm;
int main(){
//freopen("club.in","r",stdin);
//reopen("club.out","w",stdout);
cin>>t;
while(t){
        num=0;
        cin>>n;
    //    int aa=n/2,bb=n/2,cc=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
        }
      for(int i=1;i<=n/2;i++){
                int x=0,i1;
            for(int j=1;j<=n;j++){
                if(a[j].a1>=x) x=a[j].a1,i1=j;
            }
            num+=x;
            a[i1].a1=0;
      }
            numm.push_back(num);

        t--;
}
        /*
     for(int i=1;i<=n/2;i++){
        int i1,i2,i3,x=0;
        for(int j=1;j<=n;j++) x=max(x,a[i].a1),i1=j;
        x=0;
        for(int j=1;j<=n;j++) x=max(x,a[i].a2),i2=j;
        x=0;
        for(int j=1;j<=n;j++) x=max(x,a[i].a3),i3=j;

        if(i1==i2&&i2==i3){
            num+=max(a[i1].a1,max(a[i2].a2,a[i3].a3));
        }
            else if(i1==i2) num=num+max(a[i1].a1,a[i2].a2)+a[i3].a3;
                 else if(i2==i3) num=num+max(a[i3].a3,a[i2].a2)+a[i1].a1;
     }
        a[i1].a1=0,a[i1].a2=0,a[i1].a3=0;
         a[i2].a1=0,a[i2].a2=0,a[i2].a3=0;
          a[i3].a1=0,a[i3].a2=0,a[i3].a3=0;
     t--;
     numm.push_back(num);
}
*/
//fclose(stdin);
//fclose(stdout);
for(int i=0;i<numm.size();i++) cout<<numm[i]<<endl;
return 0;
}
