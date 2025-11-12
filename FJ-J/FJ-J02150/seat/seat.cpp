#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
long long z,x,c,v,bb,xx,yy;
long long b[101][101],a[101];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>z>>x;
	cin>>a[1];
	c=a[1];
	for(int i=2;i<=z*x;i++){
		cin>>a[i];
	}
	sort(a+1,a+z*x+1,cmp);
	for(int i=1;i<=z*x;i++){
		if(a[i]==c){
			v=i;
			break;
		}
	}

	for(int i=1;i<=x;i++){
		for(int j=1;j<=z;j++){
			if(i%2==1){
				b[i][j]=a[(i-1)*z+j];
				
			}
			
			else{
				b[i][z-j+1]=a[(i-1)*z+j];
			
			
		}

		if(a[(i-1)*z+j]==c){
			if(i%2==0)
			cout<<i<<" "<<z-j+1<<" ";
			else{
				cout<<i<<" "<<j<<" ";
			}
	}
}
}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
