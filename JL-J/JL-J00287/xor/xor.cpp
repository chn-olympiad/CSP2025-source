#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int m,k;
    cin>>m>>k;
    int a[m];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=0;i<m;i++){
        int c=0;
        for(int j=i;j<m;j++){
            for(int n=i;n<=j;n++){
                c=c^a[k];
            }
        }
        if(c==k) sum++;
    }
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
