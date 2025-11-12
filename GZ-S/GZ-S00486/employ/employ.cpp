//GY-S40086 贵阳市第一中学 陶昱泽
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a=1;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        a*=i;
	}
	cout<<a;
}
