#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int i=0,k=0,a[1000],m=0,count=0;
    cin>>s;
    while(s[i]!='\0'){
        if(int(s[i])>=48&&int(s[i])<=57)
        {
            a[k]=s[i];
            k++;
        }
        i++;
    }
   
    
    for(count=0;count<=k;count++){
        int c;
        for(int x=count;x<=k;x++){
            if(a[x]>a[count]){
                c=a[count];
                a[count]=a[x];
                a[x]=c;
            }
        }
    }
     for(int j=0;j<=k;j++){
        cout<<char(a[j]);
    }
    return 0;
}