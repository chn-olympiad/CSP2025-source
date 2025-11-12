#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    if(x>y){
        return true;
    }else{
        return false;
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int n=a.size();
    int num[n]={0};
    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]>='0'&&a[i]<='9'){
            num[c]=a[i]-'0';
            c++;
        }
    }
    sort(num,num+c,cmp);
    for(int i=0;i<c;i++){
        cout<<num[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
