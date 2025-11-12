#include <iostream>
#include <algorithm>
using namespace std;

int n,m,sc,a[105];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> n >> m;
    for (int i = 1;i <= n*m;++i) cin >> a[i];
    sc = a[1];
    sort(a+1,a+1+n*m,greater<int>());
    for (int i = 1;i <= n*m;++i){
        if (a[i] == sc){
        	int x = i/n,y = i%n;
            if (x*n < i) x++;
			if (!y) y += n;
			if (x%2==0) y = n-y+1;
			printf("%d %d",x,y);
            return 0;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
