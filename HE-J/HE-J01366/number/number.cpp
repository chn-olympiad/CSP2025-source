#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r"std.in);
freopen("number.out","w"std.out);
string a;
cin>>a;
long long c=a.size();
long long b[c];
long long num=0;
for(int i=0;i<a.size();i++){
        if(a[i]=='1'){
            b[i]=1;
            num++;
        }
                else if(a[i]=='2'){
            b[i]=2;
            num++;
        }
                else if(a[i]=='3'){
            b[i]=3;
            num++;
        }
                else if(a[i]=='4'){
            b[i]=4;
            num++;
        }
                else if(a[i]=='5'){
            b[i]=5;
            num++;
        }
                else if(a[i]=='6'){
            b[i]=6;
            num++;
        }
                else if(a[i]=='7'){
            b[i]=7;
            num++;
        }
                else if(a[i]=='8'){
            b[i]=8;
            num++;
        }
                else if(a[i]=='9'){
            b[i]=9;
            num++;
}
else{
    continue;
}
}
int g;
for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
    if(b[j+1]>b[j]){
    g=b[j];
    b[j]=b[j+1];
    b[j+1]=g;
    }
    }
}
for(int i=0;i<num;i++){
    cout<<b[i];
}
return 0;
}
