#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int  main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[1000100],s2[1000100];
    int i=0,j=0;
    long long max=0;
    while(cin>>s[i]){
        if(s[i]<='9'&&s[i]>='1'){
            s2[i]=s[i];
            j++;
        }
        i++;
    }
    int r=0,f[1100],s3[1010];
    i=0;
    int c=j;
    char a[1000100];
    bool t=false;
    while(t){
        if(r%2==0){
            if(s2[r]=='1'){
                f[i]=1;
            }
            if(s2[r]=='2'){
                f[i]=2;
            }
            if(s2[r]=='3'){
                f[i]=3;
            }
            if(s2[r]=='4'){
                f[i]=4;
            }
            if(s2[r]=='5'){
                f[i]=5;
            }
            if(s2[r]=='6'){
                f[i]=6;
            }
            if(s2[r]=='7'){
                f[i]=7;
            }
            if(s2[r]=='8'){
                f[i]=8;
            }
            if(s2[r]=='9'){
                f[i]=9;
            }
            if(f[i]>max){
                max=f[i];
                j--;
            }
            else{
                a[i]=f[i];
            }
        s3[r]=max;
        }
        if(r%2==1){
            if(s2[r]=='1'){
                f[i]=1;
            }
            if(s2[r]=='2'){
                f[i]=2;
            }
            if(s2[r]=='3'){
                f[i]=3;
            }
            if(s2[r]=='4'){
                f[i]=4;
            }
            if(s2[r]=='5'){
                f[i]=5;
            }
            if(s2[r]=='6'){
                f[i]=6;
            }
            if(s2[r]=='7'){
                f[i]=7;
            }
            if(s2[r]=='8'){
                f[i]=8;
            }
            if(s2[r]=='9'){
                f[i]=9;
            }
            if(f[i]>max){
                max=f[i];
                j--;
            }
            else{
                a[i]=f[i];
            }
        s3[r]=max;
        }
        r++;
        i++;
        if(j==0){
            t=true;
        }
    }
    for(int i=0;i<=c;i++){
        cout<<s3[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
