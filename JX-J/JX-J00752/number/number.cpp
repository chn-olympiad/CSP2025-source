#include<bits/stdc++.h>
using namespace std;
string s;
long long p[1000005];
int e=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<97){
            p[e]=s[i];
            e++;
        }



    }
    sort(p,p+e);
    for(int i=e-1;i>=0;i--){

        cout<<p[i]-48;
        }


    fclose(stdin);
    fclose(stdout);

    return 0;
}


