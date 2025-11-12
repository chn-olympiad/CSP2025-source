#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    
    string nipt;
    cin >> nipt;
    vector<int> ns;
    
    for (char &c:nipt) {
    	int k = (int)c;
        if ((int)'0' <= k && k <= (int)'9') {
            ns.push_back(k-(int)'0');
        }
	}

    sort(ns.begin(), ns.end());
    reverse(ns.begin(), ns.end());

    for (int &k:ns) {
        cout << k;
    }

    cout << endl;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}

