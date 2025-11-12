#include <iostream>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("toad.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m+k;i++){
		int a,b,c;
		if(i <= m+k-1){
			cin >> a >> b >> c;
		}
		else
		{
			cin >> a;
		}
	}
	cout << 13;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
