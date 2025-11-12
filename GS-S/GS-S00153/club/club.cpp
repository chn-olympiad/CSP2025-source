#include<iostream>
using namespace std;

 int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t>>n;

    int arr1[5][100000][3];
    int arr2[5][100000][3];
    for(int j=0;j<t;j++){
            for(int i=0;i<n;i++){
                for(int q=0;q<3;q++){
                  cin>>arr1[j][i][q];
            }
        }
    }
    int temp=0;
    for(int j=0;j<t;j++){
        for(int i=0;i<n;i++){
                for(int q=0;q<3;q++){
                    if(arr1[j][i][q-1]<=arr1[i][j][q]){
                        temp=arr1[i][j][q];
                        arr1[j][i][q]=arr1[j][i][q-1];
                        arr1[j][i][q-1]=temp;
                        arr2[j][i][q]=q-1;
                        arr2[j][i][q]=q;
                    }else{
                    arr2[j][i][q]=q;
                    }
                }
            }
    }
    int s1=0;
    int s2=0;
    int s3=0;
    int s4=0;
    int s5=0;

    for(int j=0;j<t;j++){
            for(int i=0;i<n;i++){
                for(int q=0;q<3;q++){
                s1+= arr1[1][i][1];
                s2+= arr1[2][i][1];
                s3+= arr1[3][i][1];
                s4+= arr1[4][i][1];
                s5+= arr1[5][i][1];
            }
        }
    }
    cout<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl<<s5;
     if(t=1){
        for(int j=0;j<t;j++){
            for(int i=0;i<n;i++){
                for(int q=0;q<3;q++){
                    if(arr1[j][i][q-1]<=arr1[i][j][q]){
                        temp=arr1[i][j][q];
                        arr1[j][i][q]=arr1[j][i][q-1];
                        arr1[j][i][q-1]=temp;
                        }
                }
        }
        for(int j=0;j<t;j++){
            for(int i=0;i<n;i++){
                for(int q=0;q<3;q++){
                s1+= arr1[1][i][1];
                }
        }
  }
  cout<<s1;
  }
    return 0;
}
return 0;
}
