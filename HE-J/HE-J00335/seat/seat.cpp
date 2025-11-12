#include<bits/stdc++.h>
using namespace std;
int yy[100007];
int n,m,kk,ji,uu;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	kk=n*m;
	for(int i=1;i<=kk;i++){
		cin>>yy[i];
	}
	ji=yy[1]; 
	sort(yy+1,yy+kk+1);
	for(int i=1;i<=kk;i++){
		if(yy[i]==ji){
			uu=kk-i+1;
		}
	}
	int shang=uu/m;
	if(uu%m!=0){
		shang++;
	}
	uu-=(shang-1)*n;
	if(shang%2==0){
		uu=n-uu+1;
	}
	cout<<shang<<" "<<uu;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
