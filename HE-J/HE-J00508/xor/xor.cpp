#include<bits/stdc++.h>
using namespace std;
long long a[1001000],b=1,c=0,d=1,e=0,f=0,g=0,z[1001000],cha[1001000];
int ch(long long aa,long long bb){
    for(int i=bb-aa+1;i<=bb;i++){
        if(cha[i]==1){
            return 0;
        }
    }
    for(int i=bb-aa+1;i<=bb;i++){
        cha[i]=1;
    }
    return 1;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>b>>c;
	for(int i=1;i<=b;i++){
        cin>>a[i];
        z[i]=a[i];
	}

	for(int i=1;i<=b;i++){
        for(int j=d;j<=b;j++){
            for(int jj=j-d+1;jj<j;jj++){
                z[j]^=a[jj];
            }

        }
        for(int j=d;j<=b;j++){
            if(z[j]==c){
                if(ch(d,j)==1)e++;
            }
            z[j]=a[j];
        }
        d++;
	}
	cout<<e;
	return 0;
}
