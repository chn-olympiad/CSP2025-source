#include<iostream>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string st;
    cin>>st;
    int i,a[10]={};
    for(i=0;i<st.size();i++){
        switch(st[i]){
            case '0':a[0]++;break;
            case '1':a[1]++;break;
            case '2':a[2]++;break;
            case '3':a[3]++;break;
            case '4':a[4]++;break;
            case '5':a[5]++;break;
            case '6':a[6]++;break;
            case '7':a[7]++;break;
            case '8':a[8]++;break;
            case '9':a[9]++;break;
            default:continue;
        }
    }
    for(i=9;i>=0;i--){
        while(a[i]>0){
            cout<<i;
            a[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
