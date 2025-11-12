#include<bits/stdc++.h>
using namespace std;
long long a[1001000],b=1,c,d,e,f,g;
char z[1001000];
int bj(int aa,int bb){
    if(aa>bb){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>b>>c;
	for(int i=1;i<=b*c;i++){
        cin>>a[i];
	}
	d=a[1];
	sort(a+1,a+b*c+1,bj);
	for(int i=1;i<=b*c;i++){
       if(d==a[i]){
            d=i;
            break;
       }
	}
	for(long long i=1;i<=c;i++){
        if(((i-1)*b+1<=d)&&((i-1)*b+b>=d)){
            cout<<i<<" ";
            if(i%2==1){
                if(d%c==0)cout<<c;
                else{
                    cout<<d%c;
                }
                return 0;
            }
            else{
                if(d%c==0)cout<<1;
                else{
                    cout<<c-d%c+1;
                }
                return 0;
            }
        }
	}
	return 0;
}
