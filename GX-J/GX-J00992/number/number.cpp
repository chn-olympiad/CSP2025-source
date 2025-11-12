#include<bits/stdc++.h>
using namespace std;
int number[100005];
int j=0;
string c;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>c;
    int s=c.size();
    while(s>=0){
        if(c[s]>='0' && c[s]<='9'){
            number[j]=int(c[s])-48;
            j++;
        }
        s--;
    }
    sort(number , number+j ,cmp);
    while(j--){
        cout<<number[j];

    }
    return 0;
}
