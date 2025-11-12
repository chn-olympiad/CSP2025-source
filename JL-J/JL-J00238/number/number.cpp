#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,z="";
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int c=0;
    vector<int> vec;
    int f;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(char(s[i])>='0'&&char(s[i])<='9'){
            vec.push_back(s[i]);
            c++;
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            if(vec[j]<vec[j+1]){
                f=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=f;
            }
        }
    }
    for(int i=0;i<c;i++){
        z+=vec[i];
    }
    cout<<z;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
