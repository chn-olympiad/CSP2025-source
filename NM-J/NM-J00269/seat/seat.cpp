#include<bits/stdc++.h>
using namespace std;
int a[100][100],n,m,b[100],asd;
bool qwe;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> b[i];
		if(i==1) asd=b[i];
	}
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n;){
		for(int j=1;j<=m;){
			for(int k=1;k<=n*m;k++){
				a[i][j]=b[k];
				if(a[i][j]==asd){
					cout << j << " " << i;
					return 0;
				            }
			    
				if(i<n&&qwe==false){
					i++;
				}else if(i>1&&qwe==true){
					i--;
				}else if(i==n&&qwe==false){
					j++;
					qwe=true;
				}else if(i==1&&qwe==true){
					j++;
					qwe=false;
				}
			}
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
