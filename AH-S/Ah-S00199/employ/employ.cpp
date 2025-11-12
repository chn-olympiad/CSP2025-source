#include<bits/stdc++.h>
using namespace std;
int x=1;
int jc(int a){
    for(int i=1;i<a;i++){
        a*=i;
    }
    cout <<(a%998244353);
    return 0;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,o=0,z=0,zb=0;
    cin >> n >>m;
    string s,c;
    cin >> s>> c;
    sort(c,c+n);
    for(int i=0;i<n;i++){
	if(s[i]=='1')o++;
	if(s[i]=='0')z++;
    }
    for(int i=0;i<n;i++){
	if(s[i]=='0')zb++;
	else if(s[i]=='1')break;
    }
    if(o<m || zb>=c[n-1] || z<c[0]){
	cout << 0;
	return 0;
    }
    if(o=n)jc(n);
    return 0;
}
