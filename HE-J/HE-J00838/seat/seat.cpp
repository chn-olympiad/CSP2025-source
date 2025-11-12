#include<bits/stdc++.h>
using namespace std;
int n,m;
int z;
int pai;//ÅÅÃû 
int a[105];
int grid[15][15];                                                                                                                                                                     
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	z=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m);
	int cnt=0;
	for(int i=n*m-1;i>=0;i--){
		cnt++;
		if(a[i]==z){
			pai=cnt;
			break; 
		}
	}
	int lie;
	if(pai%n!=0) lie=pai/n+1;
	else lie=pai/n;
	int hang=0;
	if(lie%2==0){
		hang=n-pai%n+1;
	}
	else{
		if(pai%n!=0)
		hang=pai%n;
		else
		hang=n;
	}
	cout<<lie<<' '<<hang;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
