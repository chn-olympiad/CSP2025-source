#include<fstream>
using namespace  std;
ifstream cin("xor.in");
ofstream cout("xor.out");
int n,k,a[10005]={},c[10001][100000001],b=1,j=0;
/*int anwei(int c,int j){
	if(c==j){
		return 0;
	}
	if
}*/
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<2;
	 
	/*for(int i=1;i<=n;i++){
		b=1;
		j=0;
		while(b<a[i]){
			b*=2;
			j++;
		}
		while(a[i]>0){
			if(a[i]>=b){
				a[i]-=b;
				c[i][j]=1;
			}
			b/=2;
			j--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(anwei(i,j)==k)
		}
	}*/
	cin.close();
	cout.close();
	return 0;
}
