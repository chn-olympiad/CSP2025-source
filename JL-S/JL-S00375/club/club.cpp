#include <bits/stdc++.h>
using namespace std;
int n=0,t=0;
int a[100001],b[100001],c[100001],suma,sumb,sumc;
int treata=0,treatb=0,treatc=0;
long int sum[100001];
int ak=0,bk=0,ck=0;

void funclub(int bbc,int brt){
	suma=0;
	sumb=0;
	sumc=0;
	ak=0;
	bk=0;
	ck=0;
	for (int u=1;u<=bbc;u++){
		cin>>a[u]>>b[u]>>c[u];
		suma+=a[u];
		sumb+=b[u];
		sumc+=c[u];
	}
	for (int u=1;u<=bbc;u++){
        if (suma-a[u]==sumb-b[u]&&min(sumc-c[u],sumb-b[u])==sumb-b[u]){
            if(a[u]>b[u]&&ak<=bbc/2){
                sum[brt]+=a[u];
                ak++;
                continue;
            }
            if(a[u]<b[u]&&bk<=bbc/2){
                sum[brt]+=b[u];
                bk++;
                continue;
            }
		}
		if (sumc-c[u]==sumb-b[u]&&min(sumc-c[u],suma-a[u])==sumc-c[u]){
            if(c[u]>b[u]&&ck<=bbc/2){
                sum[brt]+=c[u];
                ck++;
                continue;
            }
            if(c[u]<b[u]&&bk<=bbc/2){
                sum[brt]+=b[u];
                bk++;
                continue;
            }
		}
		if (suma-a[u]==sumb-c[u]&&min(sumc-c[u],sumb-b[u])==sumb-b[u]){
            if(a[u]>c[u]&&ak<=bbc/2){
                sum[brt]+=a[u];
                ak++;
                continue;
            }
            if(a[u]<c[u]&&ck<=bbc/2){
                sum[brt]+=c[u];
                ck++;
                continue;
            }
		}
		if (a[u]!=0&&min(9*suma-857*a[u],9*sumb-857*b[u])==9*suma-857*a[u]&&min(9*suma-857*a[u],9*sumc-857*c[u])==9*suma-857*a[u]&&ak<=bbc/2){
            sum[brt]+=a[u];
            ak++;
            continue;
		}
		if (b[u]!=0&&min(9*suma-857*a[u],9*sumb-857*b[u])==9*sumb-857*b[u]&&min(9*suma-857*a[u],9*sumc-857*c[u])==9*sumb-857*b[u]&&bk<=bbc/2){
		    sum[brt]+=b[u];
		    bk++;
		    continue;
		}
		if (c[u]!=0&&min(9*sumc-857*c[u],9*sumb-857*b[u])==9*sumc-857*c[u]&&min(9*suma-857*a[u],9*sumc-857*c[u])==9*sumc-857*c[u]&&ck<=bbc/2){
		    sum[brt]+=c[u];
		    ck++;
		    continue;
		}

		if (a[u]>b[u]&&a[u]>c[u]&&ak<=bbc/2){
            sum[brt]+=a[u];
            ak++;
            continue;
		}else if(b[u]>c[u]&&b[u]>a[u]&&bk<=bbc/2){
            sum[brt]+=b[u];
            bk++;
            continue;
        }else{
            sum[brt]+=c[u];
            ck++;
            continue;
        }
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++){
		cin>>n;
		funclub(n,i);
	}
    for (int j=1;j<=t;j++) cout<<sum[j]<<endl;
	return 0;
}
