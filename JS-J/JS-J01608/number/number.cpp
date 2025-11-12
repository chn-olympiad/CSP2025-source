#include<bits/stdc++.h>
using namespace std;
//const int MAXN=1000100;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string a;
    int nums[1000100];
    cin>>a;
    int j=0;
    for(int i=0;i<(int)a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            nums[j]=a[i]-'0';
            j++;
        }
    }
    sort(nums,nums+j,cmp);
    for(int i=0;i<j;i++){
        cout<<nums[i];
    }
    return 0;
}
