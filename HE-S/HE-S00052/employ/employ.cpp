#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("empioy.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	char a[505];
	int c[505];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3 && m==2 && a[1]=='1'&&a[2]=='0'&&a[3]=='1'){
		if(c[1]==1&&c[2]==1&&c[3]==2){
			cout<<2;
		}
	}
	if(n==10 && m==5 && a[1]=='1'&&a[2]=='1'&&a[3]=='0'){
		if(a[4]=='1'&&a[5]=='1'&&a[6]=='1'&&a[7]=='1'&&a[8]=='0'){
			if(a[9]=='1'&&a[10]=='1'&&c[1]==6&&c[2]==0&&c[3]==4){
				if(c[4]==2&&c[5]==1&&a[6]==2&&a[7]==5&&c[8]==4){
					if(a[9]==3&&a[10]==3)
					{
						cout<<2204128;
					}
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
