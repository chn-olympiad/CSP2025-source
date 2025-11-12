#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],ans;
int xorx(int x,int y){
    string sx="",sy="",z="";
    while(x!=0){
        sx=char(int('0')+x%2) + sx;
        x/2;
    }
    while(y!=0){
        sy=char(int('0')+y%2) + sy;
        y/2;
    }
    cout<<sx<<" "<<sy<<endl;
    for(int i=0;i<max(sx.size(),sy.size());i++){
        if (sy[i] == '0' && sx[i] == '1' || sy[i] == '1' && sx[i] == '0') z[i] = '1';
        else z[i] =  '0';
    }
    int summ=0;
    for(int i=z.size();i>0;i--)
    {
        summ += z[i] * pow(2,z.size() - i + 1);
    }
    return summ;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
       cin>>a[i];
    }

    cout<<k;   // pow(2,3) == 8;
    return 0;
}
