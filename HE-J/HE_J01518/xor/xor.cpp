#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int main (){
	freopen("xor.in","r","stdin");
	freopen("xor.out","w","stdout");
	int x,y;
	cin>>i>>j;
	for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            i^j;
        }
	}
	for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
                cout<<a[i][j];
        }
	}
	return 0;
}
