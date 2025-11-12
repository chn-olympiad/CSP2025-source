#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int i=s.size();
    int a[i];
    for (int j=0;j<i;j++){
        a[j]=s[j];
        if (a[j]>9){
            s.erase(1,j);
        }
    }
    i=s.size();
    for (int j=0;j<i;j++){
        a[j]=s[j];
    }
    for (int j=1;j<i;j++){
        if (a[j-1]<a[j]){
            int b=a[j-1];
            a[j-1]=a[j];
            a[j]=b;
        }
    }
    int Sum=0;
    int h=0;
    while (true){
        Sum=Sum+(pow(10,i)*a[h]);
        i--;
        h++;
        if (i==0){
            break;
        }
    }
    cout<<Sum;
    return 0;
}
