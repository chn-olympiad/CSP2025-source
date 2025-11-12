#include <iostream>
using namespace std;
int main(){
    freopen("number.in",'r',stdin);
    freopen("number.out",'w',stdout);

    string n,num[10005],a="";
    int b[0,0,0,0,0,0,0,0,0,0,0];
    int ans=0;
    cin>>n;
    for(int i=0;i<n.length();i++){
        if(n[i]<=9 and n[i]>=0){
            num[ans]=n[i];
            ans++;
        }
    }
    for(int j=0;i<=ans i++){
        if(num[i]=='0') b[0]++;
        if(num[i]=='1') b[1]++;
        if(num[i]=='2') b[2]++;
        if(num[i]=='3') b[3]++;
        if(num[i]=='4') b[4]++;
        if(num[i]=='5') b[5]++;
        if(num[i]=='6') b[6]++;
        if(num[i]=='7') b[7]++;
        if(num[i]=='8') b[8]++;
        if(num[i]=='9') b[9]++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<b[i];j++){
            a+=char(i);
        }
    }
    cout<<int(a);
    return 0;
}
