#include <bits/stdc++.h>
using namespace std;
string s;
int main ()
{
    freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
    string a;
    cin >>a;
    for (int i=0;i<a.size();i++){
        if (a[i]>='0'&&a[i]<='9'){
            s+=a[i];
        }
    }
    sort(s.begin(),s.end(),greater<char>());
    cout <<s;
    //ccf great!
	return 0;
}
