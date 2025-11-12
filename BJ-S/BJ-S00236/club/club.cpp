#include<bitts/stdc++.h>
using namespace std;
void froudMaxNum(int a[]){

}
int main(){
	int t,ans=0,group[5];
	cin>>t;
	int a[100][100];
	int n;
	cin>>n;
	for(int k=0;k<t;k++){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=3;j++){
				cin>>a[i][j];
			}
		}
	}
	
	for(int i=0;i<=group.length();i++){
		if(a[i][1]>a[i][2]&&a[i][1]>>a[i][3]){
			group[1]++;
			ans+=a[i][1];
		}
		if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
			group[2]++;
			ans+=a[i][2];
		}
		if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]){
			group[3]++;
			ans+=a[i][3];
		}
	}
	cout<<ans<<endl;
	retrun 0;
}
