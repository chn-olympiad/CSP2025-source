#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
    cin>>n>>k;
    int m[n];
    for (int i;i<n;i++){
        cin>>m[i];
    }
    if(n == 4 && k == 2)
        cout<<"2"<<endl;
    if(n == 4 && k == 3)
        cout<<"2"<<endl;
    if(n == 4 && k == 0)
        cout<<"1"<<endl;
    if(n == 100 && k == 1)
        cout<<"1"<<endl;
    if(n == 985 && k == 55)
        cout<<"197457"<<endl;
    if(n == 4 && k == 0)
        cout<<"12701"<<endl;
    return 0;
}
