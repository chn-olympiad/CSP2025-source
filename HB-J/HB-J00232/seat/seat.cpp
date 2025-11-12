#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//
	int n,m,a=1,b=1;
	cin>>n>>m;
	int arr[n][m]={0};
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                cin>>arr[i][j];
            }
        }
            for(int j=0;j<n;j++){
                for(int i=0;i<m;i++){
                    if(arr[i][j]>arr[0][0]){
                        a++;
                        if(a>n){
                            a=1;
                            b++;
                        }

                    }
                }
            }
        cout<<b<<" "<<a;
}
