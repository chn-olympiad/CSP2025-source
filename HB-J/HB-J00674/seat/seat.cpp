#include <vector>
#include <iostream>
#include <filesystem>
#include <algorithm>

using namespace std;

vector<int> a(105,-1);
int n,m;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }

    int R=a[1];

    sort(a.begin()+1,a.begin()+(n*m)+1,cmp);

    int x=1,y=1,num=0;
    while(num!=n*m){
        if(x%2!=0){
            for(y=1;y<=n;y++){
                num++;
                if(a[num]==R){
                    cout<<x<<" "<<y;
                    return 0;
                }

            }
            x++;
        }
        else{
            for(y=n;y>=1;y--){
                num++;
                if(a[num]==R){
                    cout<<x<<" "<<y;
                    return 0;
                }
            }
            x++;
        }
    }

    return 0;
}
