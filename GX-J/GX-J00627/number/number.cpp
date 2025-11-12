# include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdio);
    freopen("number.out","w",stdio);
    char a[1000005];
    cin>>a;
    int j=0;
    int b[1000005];
    for(int i=0;i<1000005;i++){
        if(a[i]>='0' && a[i]<='9'){
            b[j]=(int)a[i];
            j++;
        }
        if(a[i]=='\0'){
            break;
        }
    }
    for(int l=0;;l++){
        int d=0;
        for(int i=0;i<j;i++){
            if(b[i]>b[i-1]){
                int c=b[i-1];
                b[i-1]=b[i];
                b[i]=c;
                int d=1;
            }
        }
        if(d==0){
            break;
        }
    }
    for(int i=0;i<j;i++){
        cout<<a[i];
    }
    return 0;
}
