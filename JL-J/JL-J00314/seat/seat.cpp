#include<bits/stdc++.h>
using namespace std;
int a[11][11];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x=1,y=1,f=0;
    cin>>n>>m;
    vector<int> b(n*m);
    for(int i=0;i<n*m;i++){
        cin>>b[i];
    }
    int c=b[0];
    sort(b.begin(),b.end());
        for(int i=n*m-1;i>=0;i--){
            if(f==0){
                if(b[i]==c){
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                else if(b[i]!=c){
                     if(y<n){
                        y++;
                    }
                    else if(y=n){
                        f=1;
                        x++;
                    }
                }

            }
            else if(f==1){
                if(b[i]==c){
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                else if(b[i]!=c){
                    if(y>1){
                        y--;
                    }
                    else if(y=1){
                        f=0;
                        x++;
                    }
                }
            }
        }
    return 0;
}
