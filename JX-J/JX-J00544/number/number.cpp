#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[100001]={},k=0;
    string n;
    cin>>n;
    for(int i=0;i<n.size();i++){
        a[i]=-1;
    }
    for(int i=0;i<n.size();i++){
//        if(n[i]>='0' && n[i]<='9'){
//            a[k]=n[i]-48;
//           k++;
//       }
        if(n[i]=='0'){
            a[k]=0;
            k++;
        }
        else if(n[i]=='1'){
            a[k]=1;
            k++;
        }
        else if(n[i]=='2'){
            a[k]=2;
            k++;
        }
        else if(n[i]=='3'){
            a[k]=3;
            k++;
        }
        else if(n[i]=='4'){
            a[k]=4;
            k++;
        }
        else if(n[i]=='5'){
            a[k]=5;
            k++;
        }
        else if(n[i]=='6'){
            a[k]=6;
            k++;
        }
        else if(n[i]=='7'){
            a[k]=7;
            k++;
        }
        else if(n[i]=='8'){
            a[k]=8;
            k++;
        }
        else if(n[i]=='9'){
            a[k]=9;
            k++;
        }
//       cout<<a[i]<<" ";
    }
//    cout<<endl;
    for(int i=0;i<n.size();i++){
        for(int j=0;j<n.size()-1;j++){
                if(a[j]<a[j+1]){
                    swap(a[j],a[j+1]);
                }
        }
    }
    for(int i=0;i<n.size();i++){
        if(a[i]!=-1){
            cout<<a[i];
        }
    }
    return 0;
}
//290es1q0
//921000
