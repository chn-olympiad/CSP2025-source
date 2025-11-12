#include<iostream>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cout<<n*m<<endl;
    int a[n*m],t,i;
    for(i=0;i<n*m;i++){
        cin>>a[i];
    }
    t = a[0];
    int j;
    for(i=0;i<n*m;i++){
        for(j=1;j<n*m;j++){
            if(a[j]>a[j-1]){
                swap(a[j],a[j-1]);
            }
        }
    }
    int deemp=0;
    for(i=0;i<n*m;i++){
        if(a[i]==t){
            deemp = i+1;
            break;
        }
    }
    i = 1;
    j = 1;
    int comb=0;
    while(deemp>1){
        deemp--;
        if(comb==1){
            j--;
            if(j==0){
                j++;
                i++;
                comb = 0;
            }
        }
        else{
            j++;
            if(j==n+1){
                j--;
                i++;
                comb = 1;
            }
        }
    }
    cout<<i<<" "<<j;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
