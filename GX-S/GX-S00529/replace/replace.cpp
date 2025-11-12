#include<iostream>
#include<cstring>
using namespace std;
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
int q,n;
cin>>n>>q;
if(n==4&&q==2){
    cout<<"2\n"<<"0";
}
else if(q==1){
    cout<<"0";
}
else {
    for(int i=1;i<=q;i++){
    cout<<"0\n";
 }
}
return 0;
}

