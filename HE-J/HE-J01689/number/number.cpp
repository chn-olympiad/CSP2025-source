#include <iostream>
using namespace std;
int main(){
	
    string s;
    cin>>s;
    int arr[10000]={0};
    int o=0;
    for(int i=0;i<s.size();i++){
        if(char(s[i])>=97 && char(s[i])<=122){
            o+=0;
        }else{
            o++;
            arr[i]=s[i];
        }
    }
    for(int i=0;i<o;i++){
        if(arr[i]<arr[i+1]){
            arr[i]=arr[i+1];
            arr[i+1]=arr[i];
        }
    }
    for(int i=0;i<o;i++){
        cout<<arr[i];
    }
    cout<<endl;
}
