#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n, m;
    cin >> n >> m;
    int to= n * m;
    vector<int> a(to);
    for (int i=0;i<to;i++) {
        cin >>a[i];
    }
    int sc=a[0];
    vector<int> sor = a;
    sort(sor.begin(), sor.end(), greater<int>());
	int k = 0;
    for (int i = 0; i < to; ++i)
	{
        if (sor[i] == sc)
		{
            k = i + 1;
            break;
        }
    }
    int c=(k-1)/n;
    int p=(k-1)%n;
    int row;
    if (c%2==0)
	{
        row=p+1;
    } else {
        row=n-p;
    }
    cout<<(c+1)<<" "<<row<<endl;
    return 0;
}
