#include<bits/stdc++.h>
using namespace std;
int n,m;
string g;
int t[501];

int main () {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>g;
    for(int i=0;i<n;i++){
        cin>>t[i];
    }

    int e;
    e=n;
    int d;
    d=n-1;
    while(true){
        e=e*d;
        d--;
        if(d==0){
        	break;
		}

        }

    int p=0;
    p=e%998244353;
    cout<<p;

	return 0;

}
