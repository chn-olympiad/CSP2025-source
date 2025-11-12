#include<bits/stdc++.h>
using namespace std;
bool cmp(int n,int m){
	return n>m;
}
int main(){
	/*int n;
	srand(time(0));
	n=range()%100+1;
	cout<<n;*/
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w;
	cin>>n>>m;
	int a[n*m];
	int b[m][n];
	//cout<<n<<" "<<m<<endl;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	/*for(int i=0;i<n*m;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;*/
	w=a[0];
	int k=0;
	int s;
	sort(a,a+n*m,cmp);
	/*for(int i=0;i<n*m;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<w;*/
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if((i+1)%2!=0)
				b[i][j]=a[i*n+j];
			else{
				b[i][j]=a[n*(i+1)-(j+1)];
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		cout<<b[j][i]<<" ";
		}cout<<endl;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(b[j][i]==w){
				cout<<j+1<<" "<<i+1;
				return 0;
			}
		}
	}
	return 0;
}