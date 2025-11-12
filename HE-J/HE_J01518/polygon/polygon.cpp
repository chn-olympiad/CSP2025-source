#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int main (){
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
        for(int j;j<=n;j++){
            cin>>a[i][j];

        }
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<M=n;j++){
                sum=sum+a[i][j];
            cout<<sum;
        }
	}

	return 0;
}
