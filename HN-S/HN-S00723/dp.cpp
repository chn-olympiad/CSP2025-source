#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i=1;i<=1000;i++){
        system("./make");
        system("./solve");
        system("./bf");
        if(system("diff solve.out bf.out -Z")){
            cout<<"WA\n";
            break;
        }
        else{
            cout<<"AC on "<<i<<'\n';
        }
    }
}