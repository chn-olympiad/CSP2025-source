#include<iostream>
#include<cmath>
using namespace std;
void fenjian(int o);
int c,a[100][4],b[100],d,j,q,x,z[100],o=1,ww[100],yy[100],qq=1;
void go(int d,int p);
int main(){
	int n;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>d;
        for(int i=1;i<=d;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
     int p=d/2;
    go(d,p);
	}
	for(int i=1;i<=n;i++){
        cout<<z[i]<<endl;
	}
	return 0;
}
void go(int d,int p){
    int www=1,yyy=1;
    for(int i=1;i<p;i++){
        for(int j=1;j<=3;j++){
               for(int f=1;f<=d;f++){//shuhang
                    if(f==i||f==i+1){
                        ;
                    }else{
                        ww[www]==f;
                        www++;
                    }
               }
              for(int f1=1;f1<=3;f1++ ){//henghang
                if(f1==j){
                    break;
                }else{
                    yy[yyy]=f1;
                   yyy++;
                }
                for(int f2=1;f2<www;f2++){
                    for(int f3=1;f3<yyy;f3++){
                        b[o]=b[o]+a[i][j]+a[i+1][j];
                        b[o]=b[o]+a[ww[f2]][yy[f3]]+a[ww[f2+1]][yy[f3+1]];
                        o++;
                    }
                }
              }
        }
    }
    fenjian(o);
}
void fenjian(int o){
    int gg=b[1];
    for(int i=2;i<=o;i++){
        if(gg<b[i]){
            swap(gg,b[o]);
        }
    }
    gg=z[qq];
    qq++;
}
