#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	int s,a[11],u=1;
	cin>>s;
	int p=1,n[100005],y=0,z=1;
	while(s!=0){
        if(s%10==0){
            u*=10;
            y++;
        }
        if(s%10!=0){
            n[p]=s%10;
            p++;
        }
        s/=10;
	}
	if(p<=1){
		cout<<n[1];
		return 0;
	}
	int m=0,w=p;
	while(m<=p){
		m++;
		int b=0,k;
		for(int i=1;i<=p;i++){
			if(n[i]>=b){
				b=n[i];
				k=i;
			}
		}
		n[k]=0;
		for(int i=1;i<=w-2;i++){
            b*=10;
		}
		u+=b;
		w-=1;
		b=0;
	}
    for(int i=1;i<=y;i++){
        z*=10;
    }
	cout<<u-z;
	return 0;
}
