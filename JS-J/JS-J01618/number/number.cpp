#include<bits/stdc++.h>
using namespace std;
//#define freopen(file,mode,stream) (void)0
//#define fclose(stream) (void)0
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    vector<int> arr;
    for(char c:str){
        if(isdigit(c)){
            arr.push_back(c-'0');
        }
    }sort(arr.begin(),arr.end(),greater<int>());
    for(int i:arr){
        cout<<i;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
