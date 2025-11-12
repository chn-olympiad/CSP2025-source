#include<bits/stdc++.h>
using namespace std;
int arr[10001],arrs[50][50],cnt=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>arr[i];
    }
    int a1=arr[1];
    sort(arr+1,arr+(n*m)+1,greater<int>());
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                arrs[j][i]=arr[cnt];
                if(arr[cnt]==a1){
                    printf("%d %d",i,j);
                }
                cnt++;
            }
        }else{
            for(int j=n;j>=1;j--){
                arrs[j][i]=arr[cnt];
                if(arr[cnt]==a1){
                    printf("%d %d",i,j);
                }
                cnt++;
            }
        }
    }
	return 0;
}
