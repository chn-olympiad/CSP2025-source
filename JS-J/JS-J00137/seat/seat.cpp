#include<iostream>
using namespace std;
int a[1000001];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
    bool b=1;
    long long n,m,h=1,l=1,a1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    a1=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    int i=1;
    while(a1<a[i]){
        if(i==1){
            h++;
            i++;
            continue;
        }
        else if((h==n||h==1)&&b){
                l+=1;b=0;
        }
        else {
            if(l%2)h++;
            else h--;
            b=1;
        }
        i++;
    }
    cout<<l<<" "<<h;
    return 0;
}
