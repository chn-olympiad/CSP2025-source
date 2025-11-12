#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen('number.in','r',stdin);
	freopen('number.out','w',stdout);
	int n,k,m,a[105]={0},b[105]={0};
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		 cin>>a[i];
	}
	int r=a[0];
	for(int i=0;i<n*m;i++){
		int max=-1;
		for(int j=0;j<m*n;j++){
			if(a[j]>max){
				max=a[j];
				k=j;
			}
		}
		a[k]=0;
		b[i]=max;
	}
	for(int i=0;i<n*m;i++){
		 if(b[i]==r){
			 r=i;
			 break;
		 }
	}
	cout<<r/n<<r%n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
