#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s1,s2;
    getline(cin,s1);
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='0'&&s1[i]<='9'){
            s2=s2+s1[i];
        }
    }
    for(int i=0;i<s2.size()-1;i++){
        for(int j=0;j<s2.size()-1;j++){
            if(s2[j]<s2[j+1]){
                swap(s2[j],s2[j+1]);
            }
        }
    }
    cout<<s2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
