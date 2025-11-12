#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
char c[100005];
int a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x=1;
	cin.getline(c,100005);
	for(int i=0;i<=strlen(c);i++){
		if(c[i]>='0'&&c[i]<='9'){
			a[x]=c[i]-48;
			x++;
		}
	}
	int tot=0;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=i;j++){
			if(a[i]>a[j]){
				tot=a[j];
				a[j]=a[i];
				a[i]=tot;
			}
		}
		tot=0;
	}
	for(int i=1;i<x;i++){
		cout<<a[i];
	}
	cout.flush();
	return 0;
}
