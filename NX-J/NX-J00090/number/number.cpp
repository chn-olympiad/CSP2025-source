#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    int a[n.size()],i=0;
    for(int j=0;j<n.size();j++){
        if(n[j]>='0' and n[j]<'10'){
            a[i]=n[j];
            i++;
        }
    }
    sort(a,a+i);
    for(int j=i-1;j>=0;j--){
        if(char(a[j])>='a' && char(a[j])<='z'){
            continue;
        }
        cout<<char(a[j]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
