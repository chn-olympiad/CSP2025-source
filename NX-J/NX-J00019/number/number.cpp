#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[1000000000]={0};
    int len=s.size();
    int j=0,b=0;
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9')
        {
            a[j]=s[i]-'0';
            j++;
        }

    }
    sort(a+0,a+0+j);
    for(int i=j-1;i>=0;i--){
        cout<<a[i];
    }


    fclose(stdin);
    fclose(stdout);

    return 0;
}
