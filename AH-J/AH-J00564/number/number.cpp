#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1000000000];
    int k=1;
    cin>>s;
    for(int i=0;i<=s.length()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=s[i]-59;
            k++;
        }
    }
    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--){
        cout<<a[i];
        if(i==1){
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
return 0;
}
