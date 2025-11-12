#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a],d,e,g=0,h=0;
	for(d=0;d<a;d++){
        cin>>c[d];
	}
	for(d=0;d<a;d++){
        int f=0;
        for(e=d;e>=h;e--){
            f=c[e]^f;
            if(f==b){
                g++;
                h=d+1;
                break;
            }
        }
	}
	cout<<g;
	return 0;
}
