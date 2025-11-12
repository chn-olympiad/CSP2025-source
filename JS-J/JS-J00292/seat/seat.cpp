#include<algorithm>
#include<iostream>
#include<fstream>
using namespace std;

int k;
int n,m,t,l;
int arr[105];
int b[15][15];

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[l++];
        }
    }
    t=arr[0];
    sort(arr,arr+l,cmp);
    for(int i=0;i<m;i++){
        if(t<0){
            break;
        }
        if(i%2){
            for(int j=n-1;j>-1;j--){
                if(arr[k]==t){
                    cout<<i+1<<" "<<j+1<<endl;
                    t=-1;
                    break;
                }
                b[i][j]=arr[k++];
            }
        }
        else{
            for(int j=0;j<n;j++){
                if(arr[k]==t){
                    cout<<i+1<<" "<<j+1<<endl;
                    t=-1;
                    break;
                }
                b[i][j]=arr[k++];
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
