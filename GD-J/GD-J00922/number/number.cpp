#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string n;
long long sum,a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[sum]=n[i]-'0';
			sum++;
		}
	}
	sort(a,a+sum);
	for(int i=sum-1;i>=0;i--) printf("%d",a[i]);
}
