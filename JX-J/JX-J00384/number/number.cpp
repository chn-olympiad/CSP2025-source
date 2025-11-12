#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int t=0,max=-1,ans=-1;
    cin>>s;
    for(int i=0;i<s.size();i++){
            if(s[i]-'0'>9){
                continue;
            }
            a[t]=s[i]-'0';
            t++;

    }
   for(int i=0;i<t;i++){
        for(int j=i+1;j<t;j++){
            if(a[i]<a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }

        }
    }
    for(int i=0;i<t;i++){
        cout<<a[i];
    }
   // fclose(stdin);
    //fclose(stdout);
return 0;
}
