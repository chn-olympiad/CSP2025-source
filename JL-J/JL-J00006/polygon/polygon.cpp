#include<bits/stdc++.h>
using namespace std;
int n,a[5005],flag=0,ans=0;
void pol(int x,int y,int p,int s){
    for(int i=x;i<=n;i++){
        if(flag==1){
            flag=0;
            return;
        }
        cout<<a[i]<<" :"<<i;
        s+=a[i];
        y++;
        cout<<"--"<<y<<endl;
        if(y==p&&s>a[i]*2){
            ans++;
            cout<<111<<endl;
            return;
        }
        if(s<=a[i]*2 && y==p){
            flag=1;
            cout<<222<<endl;
            return ;
        }
        else pol(i+1,y,p,s);
        s-=a[i];
        y--;
        i++;
    }
}
int main(){
    int sum=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=3;i<=n;i++){
        pol(1,0,i,sum);
    }
    cout<<ans;
    return 0;
}
