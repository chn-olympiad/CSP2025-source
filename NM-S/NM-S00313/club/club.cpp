#include<iostream>
using namespace std;
int a[100001][3];
void person(int n){
    int max=0;
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            if(a[0][j]+a[1][k]>max&&j!=k) max=a[0][j]+a[1][k];
        }
    }
    cout<<max<<endl;
}
void person1(int n){
    int max=0;
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            for(int q=0;q<3;q++){
                for(int f=0;f<3;f++){
                    if(a[0][j]+a[1][k]+a[2][q]+a[3][f]>max&&((j==k&&j!=q&&j!=f)||(j==f&&j!=q&&j!=k)||(j==q&&j!=k&&j!=f)||(k==q&&k!=j&&k!=f)||(k==f&&k!=j&&k!=q)||(q==f&&q!=j&&q!=k))) max=a[0][j]+a[1][k]+a[2][q]+a[3][f];
                }
            }
        }
    }
    cout<<max<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
        if(n==2) person(n);
        if(n==4) person1(n);
    }
    return 0;
}
