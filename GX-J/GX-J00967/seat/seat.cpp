#include<bits/stdc++.h>
using namespace std;

bool cnp(int c,int d){
    return c>d;
}


int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int R=0,Rst=0,c=0,r=0;
    long long n,m;
    cin >> n >> m;
    vector<long long> a(n*m+1);
    for(int i=1;i<=n*m;i++) cin >> a[i];
    R = a[1];
    sort(a.begin(),a.end(),cnp);
    for(int i=1;i<=n*m;i++){
        if(R==a[i]) Rst=i;
    }
    if((Rst/n)%2==0){
        c=Rst/n+1;
        r=n-(Rst%(n*2)-1);
    }
    else{
       c=Rst/n+1;
       r=Rst%n;
    }
    cout << c <<" " << r << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
