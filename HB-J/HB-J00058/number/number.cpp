#include<bits/stdc++.h>
using namespace std;
int a[1000005],j=0;
string c;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>c;
    int len6=c.size();
    for(int i=0;i<len6;i++){
        if(c[i]>='0'&&c[i]<='9'){

            a[j]=c[i];
            j++;
        }
    }

    sort(a,a+j);
    for(int i=j-1;i>=0;i--){
        cout<<char(a[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
