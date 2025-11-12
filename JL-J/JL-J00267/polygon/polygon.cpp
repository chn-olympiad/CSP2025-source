#include<bits/stdc++.h>
using namespace std;
char a[1000001];
bool cmp(int a,int b){
    if(a<b)
    return b<a;;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    int j=1;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i];
            j++;
        }
    }
    j--;
    sort(a+1,a+j+1,cmp);
    for(int i=1;i<=j;i++){
        cout<<a[i];
    }

    return 0;

}
