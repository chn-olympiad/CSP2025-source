#include <bits/stdc++.h>
using namespace std;
int bubblesort(int length,int a[]){
    for(int i=1;i<=length;i++){
        int f=0;
        for(int j=1;j<=length-i;j++)
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                f=1;
            }
        if(f==0)
            break;
    }
    for(int j=length;j>=1;j--)
        cout<<a[j];
}
int n[200001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    long long int ji=1,i,j;
    for(i=0;int(a[i])>=0&&int(a[i])<=127;i++){
        if(a[i]>='0'&&a[i]<='9'){
            n[ji]=int(a[i]-'0');
            ji++;
        }
    }
    bubblesort(ji-1,n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
