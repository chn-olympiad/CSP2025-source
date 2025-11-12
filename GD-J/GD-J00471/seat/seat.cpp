#include <iostream>
#include <algorithm>
using namespace std;
int a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int i=1,j=1,k=1;
	while(i<n||j<m){
		if(a[k]==t){
			cout<<i<<" "<<j;
			break;
		}
		if(j==1){
			if(i%2==0)
				i++;
			else
				j++;
		}
		else if(j==m){
			if(i%2==0)
				j--;
			else
				i++;
		}
		else{
			if(i%2==0)
				j--;
			else
				j++;
		}
		k++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
