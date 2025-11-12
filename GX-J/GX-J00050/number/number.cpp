#include<bits/stdc++.h>
using namespace std;
string s;
int a[1001],l=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int num1=s.length();
    for(int i=0;i<num1;i++){
        int p=s[i];
        p-=48;
        if(p>0&&p<9){
            a[l]=p;
            l++;
        }else if(p==9||p==0){
            a[l]=p;
            l++;
        }
    }
    sort(a+1,a+1+l,cmp);
    l--;
    for(int i=1;i<=l;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

