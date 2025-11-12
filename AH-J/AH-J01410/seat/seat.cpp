#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int n,m;
vector<int> a;

void init(){
    a.push_back(0);
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;

    init();

    for(int i=1;i<=n*m;i++){
        int x;
        cin>>x;

        a.push_back(x);
    }

    int socre=a[1];
    int seat;

    sort(a.begin()+1,a.end(),[](int a,int b){
        return a>b;
    });

    for(size_t i=1;i<a.size();i++){
        if(a[i]==socre){
            seat=i;
            
            break;
        }
    }

    int c,r;

    c=ceil(1.0*seat/n);
    
    int r_=seat%n;
    bool c_=c%2;

    if(r_==0){
	    r=c_==1?n:1;
    }
    else{
	    r=c_==1?r_:(n-r_+1);
    }

    cout<<c<<" "<<r<<endl;
    return 0;
}