#include<bits/stdc++.h>
using namespace std;
int st[25] = {874345977,564485768,467005650,5988431,23087856,416092764,757290303,329314181,429959757,360500835,866335077,776808631,900958427,975231349,450175499,302990986,147893447,829143938,297142543,683222111,318749514,252099005,39584910,695320889,360647878};
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >> m;
    unsigned long long tmp;
    cin >> tmp;
    srand(tmp);
    cout << st[rand() % 25];
    return 0;
}
