#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[114514];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int ab=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<n*m;j++){
            if(a[j]<a[j+1])swap(a[j],a[j+1]);
        }
    }
    int where=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==ab)where=i;
    }
    int lie=int(where/n);
    int hang;
    if(lie*n<where)lie++;
    if(where%n==0){
        if(lie%2==1){
            hang=n;
        }
        else{
            hang=1;
        }
        cout<<lie<<' '<<hang;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(lie%2==0){
        hang=n+1-where%n;
    }
    else{
        hang=where%n;
    }
    cout<<lie<<' '<<hang;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
