#include<iostream>
#include<vector>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string input;
    cin>>input;
    vector<int> c={};
    for (int i=0;i<input.length();i++){
        char value=input[i];
        switch(value){
            case '0':c.push_back(0);break;
            case '1':c.push_back(1);break;
            case '2':c.push_back(2);break;
            case '3':c.push_back(3);break;
            case '4':c.push_back(4);break;
            case '5':c.push_back(5);break;
            case '6':c.push_back(6);break;
            case '7':c.push_back(7);break;
            case '8':c.push_back(8);break;
            case '9':c.push_back(9);break;
        }
    }
    int ith=0;
    for (int i=0;i<c.size();i++){
        if (c[ith] > c[i]){
            ith=i;
        }
        swap(c[i],c[ith]);
    }
    for (int i=0;i<c.size();i++){
        cout<<c[i];
    }
    return 0;
}
