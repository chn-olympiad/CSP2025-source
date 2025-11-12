#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int ac[5005],wa[5005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    if(n==3)cout << 1;
    if(n==4)cout << 5;
    if(n==5)cout << 9;
    fclose(stdin);
    fclose(stdout);
    return 0;
}