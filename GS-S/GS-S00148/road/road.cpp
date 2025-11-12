#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    long n=0, m=0, k=0;
    cin >> n >> m >> k;
    int M[m] = {};
    long sum =0;

    for (int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        cin >> M[i];
    }
    
    sort(M+0, M+m);
    for (int i=1; i<n; i++) {
    	sum+=M[i];
	}

    cout<<sum<<endl;
    
    return 0;
}

