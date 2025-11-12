#include<bits/stdc++.h>
using namespace std;
struct myd{
	int b1;
	int b2;
	int b3;
	bool qy=0;
};
myd a[10001];
int sum,n;
void px1(){
	bool d=0;
	for(int j=n-1;j>0;j--){
			d=1;
			for(int k=1;k<j;k++){
				if(a[k].b1<a[k+1].b1){
					myd c=a[k];
					a[k]=a[k+1];
					a[k+1]=c;
					d=0;
				}
			}
			if(d){
				return;
			}
		}
}
void px2(){
	bool d=0;
	for(int j=n-1;j>0;j--){
			d=1;
			for(int k=1;k<j;k++){
				if(a[k].b2<a[k+1].b2){
					myd c=a[k];
					a[k]=a[k+1];
					a[k+1]=c;
					d=0;
				}
			}
			if(d){
				return;
			}
		}
}
void px3(){
	bool d=0;
	for(int j=n-1;j>0;j--){
			d=1;
			for(int k=1;k<j;k++){
				if(a[k].b3<a[k+1].b3){
					myd c=a[k];
					a[k]=a[k+1];
					a[k+1]=c;
					d=0;
				}
			}
			if(d){
				return;
			}
		}
}
void zx(int b){
    if(b==1){
        	px1();
			for(int j=1,k=0;j<=n&&k<n/2;j++){
				if(a[j].qy){
					sum+=a[j].b1;
					a[j].qy=0;
					k++;
				}
			}
			return;
	}
	if(b==2){
		    px2();
			for(int j=1,k=0;j<=n&&k<n/2;j++){
				if(a[j].qy){
					sum+=a[j].b2;
					a[j].qy=0;
					k++;
				}
			}
			return;
	}
	if(b==3){
		    px3();
			for(int j=1,k=0;j<=n&&k<n/2;j++){
				if(a[j].qy){
					sum+=a[j].b3;
					a[j].qy=0;
					k++;
				}
			}
			return;
	}
}
int pd(int a,int b,int c){
	if(a>b){
		if(a>c){
			return 1;
		}else if(a==c){
			return pd(a+1,b,c);
		}else{
			return 2;
		}
	}else if(a==b){
			return pd(a,b+1,c);
	}else{
		if(a>c){
			return 2;
		}else if(a==c){
			return pd(a+1,b,c);
		}else{
			return 3;
		}
	}
}
main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,b,c,d,e[4];
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		sum=0,b=0,c=0,d=0;
		for(int j=1;j<=n;j++){
			cin>>a[j].b1;
			cin>>a[j].b2;
			cin>>a[j].b3;
			b+=a[j].b1;
			c+=a[j].b2;
			d+=a[j].b3;
			a[j].qy=1;
		}
		e[1]=max(b,max(c,d));
		e[3]=min(b,min(c,d));
		if(b!=e[1]&&b!=e[3]){
			e[2]=b;
		}else if(c!=e[1]&&c!=e[3]){
			e[2]=c;
		}else if(d!=e[1]&&d!=e[3]){
			e[2]=d;
		}
		e[1]=pd(b,c,d);
		e[2]=pd(c,b,d);
		e[3]=pd(d,b,c);
		zx(e[1]);
		zx(e[2]);
		zx(e[3]);
		cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
