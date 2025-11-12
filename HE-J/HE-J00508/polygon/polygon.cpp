#include<bits/stdc++.h>
using namespace std;
long long a[1001000],b=1,c=0,d=3,e=0,f=0,g=0,z[1001000],cha[1001000];
int dd(int aa,int bb,int cc){
    if(aa==0){
        e=0;
        f=0;
        for(int i=1;i<=b;i++){
            if(z[i]==1){
                e+=a[i];
                f=max(f,a[i]);
            }
        }
        if(e>f*2){
            g++;
        }
    }
    for(int i=cc;i<=bb;i++){
        if(z[i]==0){
            z[i]=1;
            dd(aa-1,bb,i+1);
            z[i]=0;
        }
    }
    return 0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>b;
	for(int i=1;i<=b;i++){
        cin>>a[i];
	}
	sort(a+1,a+b+1);
	for(int i=3;i<=b;i++){
        dd(i,b,1);
	}
	cout<<g;
	return 0;
}
