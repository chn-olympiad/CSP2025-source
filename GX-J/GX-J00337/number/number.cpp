#include<bits/stdc++.h>
using namespace std;
int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);



    string s;
    cin>>s;
    int a,b[1200000],h=0;

    for(int i=0;i<1000000;i++){
        a=s[i];
        if(a-48<10){
            b[i]=a-48;
        }else{
            b[i]=-1;
        }
    }
    sort(b,b+1000000);

    for(int i=1000000;i>0;i--){
        if(b[i]>=0){
            h=h*10+b[i];
        }

    }

    cout<<h;




	return 0;
}
