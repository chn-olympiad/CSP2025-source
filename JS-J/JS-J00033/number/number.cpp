#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
    string a;
    queue<int> b;
    int c[1000005],n=0;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            b.push(int(a[i])-48);
            n++;
        }
    }
    for(int i=0;i<n;i++){
        c[i]=b.front();
        b.pop();
    }
    sort(c,c+n,cmp);
    for(int i=0;i<n;i++){
        cout<<c[i];
    }
   fclose(stdin);
   fclose(stdout);
    return 0;
}
