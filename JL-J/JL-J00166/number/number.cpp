#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b[a.size()];
    for(int i=0;i<a.size();i++){
        b[i]=0;
    }
    int c=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[c]=a[i]-48;
            c++;
        }
    }
    int d;
    for(int i=0;i<c-1;i++){
        for(int j=0;j<c-1;j++){
            if(b[j]<b[j+1]){
                d=b[j+1];
                b[j+1]=b[j];
                b[j]=d;
            }
        }
    }
    for(int i=0;i<c;i++){
        cout<<b[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
