#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,ovo,qwq=1,awa=0;//n行m列 
int a[205];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
    	cin >> a[i];
	}
	int b[n][m];
	ovo=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==0){
		for(int j=1;j<=m;j++){
				b[i][j]=a[qwq];
				qwq++;
				if(b[i][j]==ovo)c=i;r=j;
				//cout << b[i][j] << " ";
			}
		}else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[qwq];
				qwq++;
				if(b[i][j]==ovo)c=i;r=j;
				//cout << b[i][j] << " ";
			}
		}
	}
	cout << c << " " << r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}