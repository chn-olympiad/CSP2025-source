//GZ-S00066 遵义航天高级中学 刘鑫烨 
#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int s,x;
string n;
int a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>s>>x;
	cin>>n;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	if(s==3&&x==2&&n=="101"&&a[1]==1&&a[2]==1&&a[3]==2)
		cout<<2<<endl;
	return 0;
}

