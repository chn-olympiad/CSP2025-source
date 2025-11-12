#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int clas[n][m];
    int sum= n*m;
    int a[sum];
    for(int i=0;i<sum;i++){
        scanf("%d",&a[i]);
    }
    int b=a[0];
    int seat=sum-1;

    sort(a,a+sum);

	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				clas[j][i]=a[seat];
				seat--;
				if(clas[j][i]==b){
					cout<<i+1<<" "<<j+1;
				}
			}
		}else{
			for(int j=n-1;j>=0;j--){
				clas[j][i]=a[seat];
				seat--;
				if(clas[j][i]==b){
					cout<<i+1<<" "<<j+1;
				}
			}
		}
	}

    fclose(stdin);
    fclose(stdout);
    return 0;
}
