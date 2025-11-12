#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char c;
    c=getchar();
    while(c!='-'&&(c<'0'||c>'9')){
        c=getchar();
    }
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}

int main(){
    string a,x[100000],y="";
    int cnt=0;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            cnt++;
            x[cnt]=a[i];
        }
    }
    sort(x+1,x+cnt+1);
    for(int i=cnt;i>=1;i--){
        y+=x[i];
    }
    cout<<y;
    return 0;
}
