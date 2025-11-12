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
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>z;
	c=strlen(z);
	for(int i=0;i<c;i++){
        if(z[i]>='0'&&z[i]<='9'){
            a[b]=z[i]-'0';
            b++;
        }
	}
	sort(a+1,a+b,bj);
	for(int i=1;i<b;i++){
        cout<<a[i];
	}
	return 0;
}
