#include<iostream>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t;
    int s1,s2,s3,num=0,l=0;
    cin>>t;
    for(int i=0;i<t;i++){
            l=0;
            cin>>n;
        for(int j=0;j<n;j++){
            cin>>s1>>s2>>s3;
            num=max(s1,s2);
            num=max(num,s3);
            l+=num;
        }
        cout<<l<<endl;
    }
    return 0;
}
