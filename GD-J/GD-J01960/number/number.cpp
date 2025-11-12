#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int book[10]={0};
    for(int i=0;i<1001;i++){
        if(s[i]==0||[i]==9){
            book[s[i]]+=1;
        }
        cout<<s[i]<<endl;
    }
    for(int i=0;i<10;i++)
        cout<<book[i]<<endl;





    return 0;
}
