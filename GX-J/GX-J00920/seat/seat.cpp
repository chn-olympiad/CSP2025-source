#include <iosteam>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	int n,m;
	cin >> n >> m;
	int a[n][m];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> a[i][j];
		}
	}
	int t = a[0][0];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i][j] > a[0][0]){ 
				a[0][0] == a[i][j];
				cout << i << " " << j;
				
			}
			
		}
	}
	
	return 0;
}
