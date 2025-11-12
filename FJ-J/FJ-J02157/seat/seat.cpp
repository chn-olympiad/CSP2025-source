#include <iostream>
#include <vector>
using namespace std;
int main() {
	freopen("seat.in","w",NULL);
	freopen("seat.out","o",NULL);
	int m,n;
	cin>>m>>n;
	vector<int> an(n*m);
	vector<vector<int>> a(n,vector<int>(m,0));
	for(int i=0;i<n*m;i++){
		cin>>an[i];
	}
	int num=an[0];
	for(int i=0;i<n*m-1;i++){
		for(int j=i;j<n*m;j++){
			if(an[i]<an[j]){
				int temp = an[i];
				an[i]=an[j];
				an[j]=temp;
			}
		}
	}
	for(int i=0,c=0;i<m;i++){
		for(int j=0;j<n;j++){
			a[i][j]=an[c++];
		}
		i++;
		for(int j=n-1;j>=0;j--){
			a[i][j]=an[c++];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[j][i] == num){
				cout<<j+1<<" "<<i+1;
			}
		}
	}
	return 0;
}
