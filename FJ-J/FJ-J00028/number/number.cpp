#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int b[N];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int aw=a.size();
	int bw=0;
	for(int i=0;i<aw;i++){
		if(a[i]>='0'&&a[i]<='9'){
			bw++;
			b[bw]=a[i]-'0';
		}
	}
	sort(b+1,b+bw+1);
	for(int i=bw;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}