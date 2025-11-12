#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r"std.in);
freopen("polygon.out","w"std.out);
int a,b;
cin>>a>>b;
int num[a*b];
int g=0;
int n=1;
int hang=0;
int lie=0;

for(int i=0;i<a*b;i++){
    cin>>num[i];
}
int rrr=num[0];
for(int i=0;i<a*b-1;i++){
        for(int j=0;j<a*b-1;j++){
    if(num[j+1]>num[j]){
            if(num[j]==rrr){
                n+=1;
            }
    g=num[j];
    num[j]=num[j+1];
    num[j+1]=g;
    }
    }
}

if((n%a)==0){
        if((n/a)%2==0){
     //       hang=a-(n%a);
     //       lie=n/a+1;
            hang=1;
            lie=n/a;    //snuangshuhang teshu
        }
        else{
          //  hang=n%a;
            //lie=n/a ;
            hang=a;
            lie=n/a;
        }
    }
    else{
        if(((n/a)+1)%2==0){
            hang=a-(n%a)+1;
            lie=n/a+1;
         //   hang=1;
          //  lie=n/a;
        }
        else{
            hang=n%a;
            lie=n/a+1;
            //hang=a;
          //  lie=n/a+1;
        }
    }
    cout<<lie<<' '<<hang<<endl;
return 0;
}
