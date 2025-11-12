#include <bits/stdc++.h>
using namespace std;

int n,t,c[5],l;
int a[100000][3];
int e[100000];
int j[100000];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        for(int j=0;j<n;j++){
            for(int u=0;u<3;u++){
                cin >> a[j][u];
            }
        }
        for(int z=0;z<n;z++){
            for(int r=0;r<3;r++){
                for(int w=0;w<3;w++){
                    if(a[z][w]<a[z][w+1]){
                        int y=a[z][w+1];
                        a[z][w+1]=a[z][w];
                        a[z][w]=y;
                    }
                }
            }
        }
        for(int z=0;z<3;z++){
            for(int r=0;r<n;r++){
                for(int w=0;w<n;w++){
                    if(a[w][z]<a[w+1][z]){
                        int y=a[w+1][z];
                        a[w+1][z]=a[w][z];
                        a[w][z]=y;
                    }
                }
            }
        }
        for(int o=0;o<3;o++){
            int x=0;
            for(int q=0;q<n;q++){
                if(x==n/2){
                    break;
                }
                if(j[q]==0){
                    c[l]=c[l]+a[q][o];
                    j[q]=1;
                    x++;
                }
            }
        }
        l++;
    }
    for(int i=0;i<l;i++){
        cout << c[i] << endl;
    }
}
