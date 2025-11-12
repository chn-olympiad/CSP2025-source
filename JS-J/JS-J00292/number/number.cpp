#include<algorithm>
#include<iostream>
#include<fstream>
using namespace std;

int l;
string s;
int arr[1000005];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
            arr[l++]=s[i]-'0';
        }
    }
    sort(arr,arr+l);
    for(int i=l-1;i>-1;i--){
        cout<<arr[i];
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
