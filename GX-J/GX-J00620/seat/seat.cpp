#include<bits/stdc++.h>
using namespace std;
int n,m,c;
string s;
bool h(int a,int b){
return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n][m],b[n*m];
	for(int i=1;i<=n*m;i++){
        cin>>b[i];
	}
	c=b[1];
	int d=1;
	sort(b+1,b+n*m+1,h);
	for(int i=1;i<=n;i++){
        if(i%2!=0){
            for(int j=1;j<=m;j++,d++){
                a[i][j]=b[d];
                cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
            }
        }
        else{
            for(int j=m;j>0;j--,d++){
                a[i][j]=b[d];
                cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
            }
        }
	}
	for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==c)
                    cout<<a[i][j]<<" "<<i<<" "<<j;
            }
	}
	return 0;
}
