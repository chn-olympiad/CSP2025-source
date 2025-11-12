#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a*b],d,e,f=1,g=1;
	for(d=0;d<a*b;d++){
        cin>>c[d];
        if(d==0){
            e=c[d];
        }
	}
	sort(c,c+a*b);
	for(d=a*b-1;d>=0;d--){
        if(c[d]==e){
            cout<<g<<" "<<f;
            return 0;
        }
        if(g%2==1){
            if(f==a){
                g++;
            }
            else{
                f++;
            }
        }
        else{
            if(f==1){
                g++;
            }
            else{
                f--;
            }
        }
	}
	return 0;
}
