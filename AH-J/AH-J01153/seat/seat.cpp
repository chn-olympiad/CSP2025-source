#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int stu[n*m]={};//students
    for(int i=0;i<n*m;i++)
    cin>>stu[i];
    int wantion=stu[0];
    sort(stu,stu+m*n,cmp);
    int wharetion=0;
    for(int i=0;i<m*n;i++)
        if(stu[i]==wantion)
        wharetion=i;
    //cout<<wharetion<<endl;//testing 1
    if(wharetion/n%2==0)
    {
        cout<<wharetion/n+1<<" "<<1+wharetion%n<<endl;
    }
    else{
        cout<<wharetion/n+1<<" "<<n-wharetion%n<<endl;
    }
    return 0;
}
