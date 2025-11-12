#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
vector<pair<int,int>> vis;
struct area{
    int k,l,r;
};
vector<area> areas;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    a.resize(n+1);
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    areas.resize(n+1);
    for (int l=1;l<=n;l++) {
        area temp ={};
        temp.k = a[l];
        temp.l = l;
        for (int r=1;r<=n;r++) {
            if (l>r) {
                continue;
            } else {
                temp.r = r;
                temp.k = temp.k ^ a[r];
            }
        }
        areas.push_back(temp);
    }
    int cnt = 0;
    for (auto i : areas) {
        if (i.k == k) {
            cnt++;
            vis.push_back({i.l,i.r});
        }
    }
    for (auto i : vis) {
        for (auto j : vis) {
            if (i.first>=j.second || i.second<=j.first && i.first!=-1 && i.second != -1) {
                cnt--;
                i.first = -1;
                i.second = -1;
                
            }
        }
    }
    cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
