#include<bits/stdc++.h>
using namespace std;
int a[100],b[100];
int main(){
    freopen("xor.in",'r',stdin);
    freopen("xor.out",'w',stout);
    int n,k,s=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    b[0]=a[0];
    for(int i=1;i<n;i++){
        b[i]=b[i-1]^a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(b[i]==b[j] && b[i]==k){
                s++;
            }
            else if(b[j]-b[j]==k){
                s++;
            }
        }
    }
    cout<<s;
    fclose(stdin)
    fclose(stdout);
    return 0;
}
