#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int l=a.size(),c=0;
    vector<int> s(l);
    for(int i=0,j=0;i<l;i++){
        if(a[i]=='1'){
            s[j]=1;
            j++;
        }
        else if(a[i]=='2'){
            s[j]=2;
            j++;
        }
        else if(a[i]=='3'){
            s[j]=3;
            j++;
        }
        else if(a[i]=='4'){
            s[j]=4;
            j++;
        }
        else if(a[i]=='5'){
            s[j]=5;
            j++;
        }
        else if(a[i]=='6'){
            s[j]=6;
            j++;
        }
        else if(a[i]=='7'){
            s[j]=7;
            j++;
        }
        else if(a[i]=='8'){
            s[j]=8;
            j++;
        }
        else if(a[i]=='9'){
            s[j]=9;
            j++;
        }
        else if(a[i]=='0'){
            s[j]=0;
            j++;
        }
        c=j;

    }
    sort(s.begin(),s.end());
    for(int i=l-1;i>l-c-1;i--){
        cout<<s[i];
    }
    cout<<endl;
}
