#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a,b,c,m,sum=0,A,B,C;
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n;
        for(int j=1;j<=n;j++){
            cin >> a >> b >> c;
            if(a>b && a>c){
                m=a;
                A++;
                if(A> n/2){
                    m!=a;
                    A--;
                    if(b>c){
                        m=b;
                        B++;
                    }
                    else{m=c;C++;}
                }
            }
            else if(b>a && b>c){
                m=b;
                B++;
                if(B> n/2){
                    m!=b;
                    B--;
                    if(a>c){
                        m=a;
                        A++;
                    }
                    else{m=c;C++;}
                }
            }
            else if(c>a && c>b){
                m=c;
                C++;
                if(C> n/2){
                    m!=c;
                    C--;
                    if(a>b){
                        m=a;
                        A++;
                    }
                    else {m=b;B++;}
                }
            }
            sum=sum + m;

        }
    }
    cout << sum<<endl;







return 0;}
